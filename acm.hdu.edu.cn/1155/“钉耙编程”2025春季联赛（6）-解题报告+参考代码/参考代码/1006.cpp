#include<bits/stdc++.h>

using i64 = long long;

const int M = 1e9 + 7;

struct SuffixArray {
    int n;
    std::vector<int> sa, rk, lc;
    std::vector<int> lg;
    std::vector<std::vector<int>> f;
    SuffixArray(const std::string& s) {
        n = s.size();
        sa.resize(n);
        lc.resize(n - 1);
        rk.resize(n);
        std::iota(sa.begin(), sa.end(), 0);
        std::sort(sa.begin(), sa.end(), [&](int a, int b) {
            return s[a] < s[b];
        });
        rk[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
        }
        int k = 1;
        std::vector<int> tmp;
        tmp.reserve(n);
        std::vector<i64> cnt(n);
        while (rk[sa[n - 1]] < n - 1) {
            tmp.clear();
            for (int i = 0; i < k; i++) {
                tmp.push_back(n - k + i);
            }
            for (auto i : sa) {
                if (i >= k) tmp.push_back(i - k);
            }
            std::fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; i++) {
                cnt[rk[i]]++;
            }
            for (int i = 1; i < n; i++) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                sa[--cnt[rk[tmp[i]]]] = tmp[i];
            }
            std::swap(rk, tmp);
            rk[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                int t = 0;
                t |= tmp[sa[i - 1]] < tmp[sa[i]];
                if(!t) t |= sa[i - 1] + k == n;
                if(!t) t |= tmp[sa[i - 1] + k] < tmp[sa[i] + k];
                rk[sa[i]] = rk[sa[i - 1]] + t;
            }
            k *= 2;
        }
        for (int i = 0, j = 0; i < n; i++) {
            if (rk[i] == 0) j = 0;
            else {
                if(j > 0) j--;
                while (1) {
                    if(i + j >= n) break;
                    if(sa[rk[i] - 1] + j >= n) break;
                    if(s[i + j] != s[sa[rk[i] - 1] + j]) break;
                    j++;
                }
                lc[rk[i] - 1] = j;
            }
        }
        lc.insert(lc.begin(), 0);
        init();
    }
    void init() {
        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i >> 1] + 1;
        }
        f.assign(n + 1, std::vector<int>(lg[n] + 1));
        for (int i = 1; i <= n; i++) {
            f[i][0] = lc[i];
        }
        for (int j = 1; j <= lg[n]; j++) {
            for (int i = 1; i <= n - (1 << j) + 1; i++) {
                f[i][j] = std::min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int ask(int x, int y) {
        x++;
        int l = lg[y - x + 1];
        return std::min(f[x][l], f[y - (1 << l) + 1][l]);
    }
};

struct DSU {
    std::vector<int> f, siz, l, r, k;
    DSU(int n) : f(n + 1), siz(n + 1, 1), k(n + 1) {
        std::iota(f.begin(), f.end(), 0);
        l = r = f;
    }
    void init(int n) {
        f.resize(n + 1);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n + 1, 1);
        l = r = f;
    }
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        k[x] += k[y];
        l[x] = std::min(l[x], l[y]);
        r[x] = std::max(r[x], r[y]);
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};

std::vector<i64> solve(int n, int m, std::string s, std::string t) {
    std::reverse(s.begin(), s.end());
    std::reverse(t.begin(), t.end());
    std::string ss = s + "{" + t;
    SuffixArray sa(ss);
    DSU dsu(n + m + 1);
    std::vector<std::pair<int, int>> b(n + m);
    for (int i = 1; i <= n + m; i++) {
        b[i - 1] = {sa.lc[i], i};
    }
    std::sort(b.begin(), b.end(), std::greater<std::pair<int, int>>());
    std::vector<i64> c(n + m + 2);
    for (int i = 0; i <= n + m; i++) {
        if (sa.sa[i] > n) {
            dsu.k[i] = 1;
        }
    }
    for (auto [lc, id] : b) {
        {
            int l = dsu.l[dsu.find(id - 1)];
            int r = dsu.r[dsu.find(id - 1)];
            int k = dsu.k[dsu.find(id)];
            c[l] += 1ll * lc * k;
            c[r + 1] -= 1ll * lc * k;
        }
        {
            int l = dsu.l[dsu.find(id)];
            int r = dsu.r[dsu.find(id)];
            int k = dsu.k[dsu.find(id - 1)];
            c[l] += 1ll * lc * k;
            c[r + 1] -= 1ll * lc * k;
        }
        dsu.merge(id, id - 1);
    }
    i64 res = 0;
    std::vector<i64> ans(n);
    for (int i = 0; i < n + m + 1; i++) {
        res += c[i];
        if (sa.sa[i] < n) ans[n - sa.sa[i] - 1] = res;
    }
    return ans;
}

struct Manacher {
    std::string s;
    int n;
    std::string str;
    std::vector<int> len;
    Manacher(std::string s) : s(s), n(s.size() * 2 + 3) {
        if (s[0] == ' ') s = s.substr(1, s.size());
        init(str);
        build(len);
    }
    void init(std::string& str) {
        str = "$#";
        for (auto& i : s) {
            str += i;
            str += '#';
        }
        str += '@';
    }
    void build(std::vector<int>& len) {
        len = std::vector<int>(n, 0);
        int l = 1, r = 1, p = 1;
        for (int i = 2; i <= n - 3; i++) {
            if (i > r) {
                l = r = p = i;
                while (str[l - 1] == str[r + 1]) {
                    l--;
                    r++;
                }
                len[i] = r - p;
            }
            else {
                len[i] = len[2 * p - i];
                if (i + len[i] >= r) {
                    p = i;
                    l = 2 * p - r;
                    while (str[l - 1] == str[r + 1]) {
                        l--;
                        r++;
                    }
                    len[i] = r - p;
                }
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, m;
        std::cin >> n >> m;
        std::string s, t;
        std::cin >> s >> t;
        auto rs = s;
        auto rt = t;
        std::reverse(rs.begin(), rs.end());
        std::reverse(rt.begin(), rt.end());
        std::vector<i64> sas = solve(n, m, s, rt);
        std::vector<i64> sat = solve(m, n, rt, s);
        std::reverse(sat.begin(), sat.end());
        Manacher ms(s);
        Manacher mt(t);
        std::vector<int> a(n + 2), b(m + 2);
        for (int i = 1; i < ms.len.size(); i++) {
            int r = i >> 1;
            int t = ms.len[i] + 1 >> 1;
            int l = r - t + 1;
            a[l]++;
            a[r + 1]--;
        }
        for (int i = 1; i <= n + 1; i++) {
            a[i] += a[i - 1];
        }
        for (int i = 1; i < mt.len.size(); i++) {
            int l = i + 1 >> 1;
            int t = mt.len[i] + 1 >> 1;
            int r = l + t - 1;
            b[l]++;
            b[r + 1]--;
        }
        for (int i = 1; i <= m + 1; i++) {
            b[i] += b[i - 1];
        }
        i64 ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += (sas[i - 1] % M) * a[i + 1] % M;
            ans %= M;
        }
        for (int j = 1; j <= m; j++) {
            ans += (sat[j - 1] % M) * b[j - 1] % M;
            ans %= M;
        }
        for (int i = 1; i <= n; i++) {
            ans += sas[i - 1];
            ans %= M;
        }
        std::cout << ans << "\n";
    }
}