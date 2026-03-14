#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;

struct dsu {
    int fa[MAXN];
    void init(int n) { iota(fa + 1, fa + n + 1, 1); }
    int find(int x) {
        while (fa[x] != fa[fa[x]])fa[x] = fa[fa[x]], x = fa[x];
        return fa[x];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x != y)fa[x] = y;
    }
}ds;



void solve() {
    int n;
    cin >> n;
    ds.init(n);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if (i + x <= n)ds.merge(i, i + x);
        if (i - x >= 1)ds.merge(i, i - x);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)ans += ds.find(i) == i;
    cout << ans - 1 << '\n';
}


signed main(signed argc, char const* argv[]) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int TxT = 1; cin >> TxT;
    while (TxT--)
        solve();
    return 0;
}
