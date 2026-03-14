#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 5e5 + 5, LOG = 20;

int n, m, q;

template<const int MAXN>
struct Sa {
    string s;
    int SA[MAXN], rk[MAXN], oldrk[MAXN << 1], id[MAXN], key1[MAXN], cnt[MAXN];
    int height[MAXN], n;
    bool cmp(int x, int y, int w) {
        return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
    }
    void getSA(int _n) {
        memset(cnt, 0, sizeof(cnt));
        memset(rk, 0, sizeof(rk));
        n = _n;
        int m = 127;
        for (int i = 1; i <= n; ++i)++cnt[rk[i] = s[i]];
        for (int i = 1; i <= m; ++i)cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; --i)SA[cnt[rk[i]]--] = i;
        for (int len = 1, p;; len <<= 1, m = p) {
            p = 0;
            for (int i = n; i > n - len; --i)id[++p] = i;
            for (int i = 1; i <= n; ++i)
                if (SA[i] > len)id[++p] = SA[i] - len;
            memset(cnt, 0, sizeof(cnt));
            for (int i = 1; i <= n; ++i)++cnt[key1[i] = rk[id[i]]];
            for (int i = 1; i <= m; ++i)cnt[i] += cnt[i - 1];
            for (int i = n; i >= 1; --i)SA[cnt[key1[i]]--] = id[i];
            memcpy(oldrk + 1, rk + 1, n * sizeof(int));
            p = 0;
            for (int i = 1; i <= n; ++i)
                rk[SA[i]] = cmp(SA[i], SA[i - 1], len) ? p : ++p;
            if (p == n)break;
        }
        // for (int i = 1; i <= n; ++i)printf("%d ", SA[i]); printf("\n");
        // for (int i = 1; i <= n; ++i)printf("%d ", rk[i]); printf("\n");
    }
    void getHeight() {
        for (int i = 1, k = 0; i <= n; ++i) {
            if (rk[i] == 0)continue;
            if (k)--k;
            while (s[i + k] == s[SA[rk[i] - 1] + k])++k;
            height[rk[i]] = k;
        }
    }
    int com[MAXN];
    void getcom(int lim) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (SA[i] > lim) com[SA[i] - lim - 1] = res = min(res, height[i]);
            else res = inf;
        }
        res = 0;
        for (int i = n; i >= 1; --i) {
            if (SA[i] > lim) com[SA[i] - lim - 1] = max(com[SA[i] - lim - 1], res), res = min(res, height[i]);
            else res = height[i];
        }
    }
}; Sa<MAXN << 1> p;

struct ST {
    int f[MAXN][LOG], n;
    void init(int* a, int _n) {
        memset(f, 0, sizeof(f));
        n = _n;
        for (int i = 1; i <= n; ++i)f[i][0] = i + a[i];
        for (int j = 1; j < LOG; j++)
            for (int i = 1; i <= n - (1 << j) + 1; i++)
                f[i][j] = f[f[i][j - 1]][j - 1];
    }
    int ask(int l, int r) {
        int res = 0;
        for (int i = LOG - 1; i >= 0; --i) {
            if (f[l][i] && f[l][i] <= r) {
                l = f[l][i];
                res += 1 << i;
            }
        }
        if (f[l][0] > r)res++; else return -1;
        return res;
    }
}st;


void solve() {
    string s, t;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    p.s = " " + s + "#" + t;
    p.getSA(n + m + 1);
    p.getHeight();
    p.getcom(n);
    st.init(p.com, m);
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        printf("%d\n", st.ask(l, r));
    }
}
signed main(signed argc, char const* argv[]) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int TxT = 1; cin >> TxT;
    while (TxT--)
        solve();
    return 0;
}

