#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, q;
string s;
int cnt[26][N], dv[26][N], lp[N];
int nxt[N];

void dfs(int l, int r, char t) {
    if (t < 'a' || l >= r) return;
    vector<int> vec;
    for (int i = l; i <= r; ++i)
        if (s[i] == t)
            vec.push_back(i);
    if (vec.empty()) return dfs(l, r, t - 1);
    vector<int> stk;
    int n = vec.size();
    for (int i = n - 1; i >= 0; --i) {
        int lcp = 0;
        auto cmp = [&](int x, int y) -> bool {
            int i = x, j = y;
            for (; i < y && j <= r; ++i, ++j)
                if (s[i] != s[j]) return lcp = i - x, s[i] > s[j];
            lcp = i - x;
            if (i == y && j > r) {
                return true;
            } else if (i == y) {
                return false;
            } else {
                return true;
            }
        };
        while (!stk.empty() && cmp(vec[i], stk.back())) stk.pop_back();
        if (!stk.empty()) nxt[vec[i]] = stk.back() + lcp;
        stk.push_back(vec[i]);
    }
    dfs(l, vec[0] - 1, t - 1);
    dfs(vec.back() + 1, r, t - 1);
    for (int i = 1; i < n; ++i) dfs(vec[i - 1] + 1, vec[i] - 1, t - 1);
}
bool check(int l, int r) { return nxt[l] <= r; }

void init() {
    for (int i = 0; i < 26; ++i) {
        memset(cnt[i] + 1, 0, sizeof(int) * n);
        memset(dv[i] + 1, 0, sizeof(int) * n);
    }
    memset(nxt + 1, 0x3f, sizeof(int) * n);
    for (int i = 0; i < 26; ++i)
        for (int j = 1; j <= n; ++j) {
            cnt[i][j] = cnt[i][j - 1] + (s[j] == 'a' + i);
        }
    for (int i = 1; i <= n; ++i)        // lf 与这个字符相同的连续最左边
        lp[i] = (s[i] == s[i - 1] ? lp[i - 1] : i);
    for (int i = 0; i < 26; ++i) {      // dv[i][j] 选字符 j 的话，这段最多能划分为几段
        bool suf = 0;                   // 若j = y, str = yyzy 第二个y肯定不能单独一段，但是1,3个可以
        for (int j = n; j >= 1; --j) {
            if (s[j] < 'a' + i) {
                dv[i][j]++;
                suf = 0;
            } else if (s[j] == 'a' + i) {
                if (!suf) dv[i][j]++;
            } else {
                suf = 1;
            }
        }
        for (int j = 1; j <= n; ++j)
            dv[i][j] += dv[i][j - 1];
    }
    dfs(1, n, 'z');
}

void solve() {
    cin >> s; n = s.size(); s = " " + s;
    init();

    cin >> q;
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        if (k == 1) { cout << "YES\n"; continue; }
        if (r - l + 1 < k) { cout << "NO\n"; continue; }

        auto sup = [&](int l, int r, int c)->int {
            if (s[r] != 'a' + c || dv[c][r] > dv[c][r - 1]) return 0;
            return min(r - l + 1, r - lp[r] + 1);
        };      // 避免询问 [axx]z 认为，x不能被划分为一段
        auto getp = [&](int l, int r, int t, int* arr, int c)->int {
            int L = arr[l - 1], LP = l;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (arr[mid] - L + sup(LP, mid, c) >= t) r = mid;
                else l = mid + 1;
            }
            return r;
        };

        bool ans = false;

        vector<int>foo(26, 0);
        foo[0] = cnt[0][r - 1] - cnt[0][l - 1];
        for (int i = 1; i < 25; ++i)foo[i] = cnt[i][r - 1] - cnt[i][l - 1] + foo[i - 1];

        for (int i = 25; i >= 0; --i) {
            // 特判一些情况，比如首字符大于 i (或者 yz, i = y 不成立)，或者整个串都不能划分到 k - 1 个字典序小于 "i" 的，或者这段没有 i 字符
            if (dv[i][l] - dv[i][l - 1] == 0 && !(s[r] == 'a' + i && lp[r] <= l)) break;
            if (dv[i][r] - dv[i][l - 1] + sup(l, r, i) < k - 1) break;
            if (cnt[i][r] - cnt[i][l - 1] == 0) continue;
            // 特殊情况：最后一个字符是 i 字符，且前面字符小于 i
            if (s[r] == 'a' + i && s[l] < 'a' + i && foo[i - 1] >= k - 1) {
                ans = true; break;
            }
            // 二分找到前面划分 k - 1 段，最少需要的长度
            int p = getp(l, r, k - 1, dv[i], i);
            if (p == r) continue;
            if (cnt[i][p] - cnt[i][l - 1] == 0) { ans = true; break; }
            if (cnt[i][r - 1] - cnt[i][p] == 0) continue;
            // 长度大于 k - 1 代表，可能有字符合并，那么肯定有字符小于 i 那么这段，可以直接扩展
            // 这段字符等于 i 的个数小于 k - 1，避免形如 z|z|z|zyy|zxx 情况，前面全是 i 字符
            if (p - l + 1 > k - 1 || cnt[i][p] - cnt[i][l - 1] < k - 1) { ans = true; break; }
            // 一定是 z|z|z|zyy|zxx 情况。即判断 zyyzxx 能否划分为 2 段，第二段更大
            if (check(p, r)) { ans = true; break; }
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }

}

signed main(signed argc, char const* argv[]) {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int TxT = 1; cin >> TxT;
    while (TxT--)
        solve();
    return 0;
}
