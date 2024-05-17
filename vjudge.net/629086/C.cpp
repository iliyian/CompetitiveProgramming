// date: 2024-05-16 21:02:15
// tag: 

#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n + 1);
  vector<int> in(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    in[u]++, in[v]++;
  }
  vector<int> dep(n + 1), siz(n + 1), rnk(n + 1), dfn(n + 1), son(n + 1), top(n + 1), pa(n + 1);
  int dfncnt = 0;
  auto dfs1 = [&](auto self, int u) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (!dep[v]) {
        dep[v] = dep[u] + 1;
        pa[v] = u;
        self(self, v);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) {
          son[u] = v;
        }
      }
    }
  };
  auto dfs2 = [&](auto self, int u, int t) {
    dfn[u] = ++dfncnt;
    rnk[dfncnt] = u;
    top[u] = t;
    if (!son[u]) return;
    self(self, son[u], t);
    for (int v : g[u]) {
      if (v != pa[u] && v != son[u]) {
        self(self, v, v);
      }
    }
  };
  dep[1] = 1;
  dfs1(dfs1, 1);
  dfs2(dfs2, 1, 1);

  vector<int> d((n + 5) << 2);

  auto pushup = [&](int p) {
    d[p] = d[lc] * d[rc] % mod;
  };

  auto build = [&](auto self, int l, int r, int p) -> void {
    if (l == r) {
      d[p] = max(in[rnk[l]] - 1, 1ll);
      return;
    }
    int mid = (l + r) / 2;
    self(self, l, mid, lc);
    self(self, mid + 1, r, rc);
    pushup(p);
  };
  build(build, 1, n, 1);

  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l <= s && t <= r) return d[p];
    int mid = (s + t) / 2, ans = 1;
    if (l <= mid) ans *= self(self, l, r, s, mid, lc), ans %= mod;
    if (r > mid) ans *= self(self, l, r, mid + 1, t, rc), ans %= mod;
    return ans;
  };

  auto hldquery = [&](int x, int y) {
    int ans = 1;
    while (top[x] != top[y]) {
      if (dep[top[x]] < dep[top[y]]) swap(x, y);
      ans *= query(query, dfn[top[x]], dfn[x], 1, n, 1);
      ans %= mod;
      x = pa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    ans *= query(query, dfn[x], dfn[y], 1, n, 1);
    ans %= mod;
    return ans;
  };

  auto exgcd = [](auto self, int a, int b, int &x, int &y) -> void {
    if (b == 0) {
      x = 1, y = 0;
      return;
    }
    self(self, b, a % b, y, x);
    y -= a / b * x;
  };

  for (int _ = 1; _ <= q; _++) {
    int s, t;
    cin >> s >> t;

    int ans = hldquery(s, t), x, y;
    exgcd(exgcd, max(in[s] - 1, 1ll), mod, x, y);
    x = (x % mod + mod) % mod;
    ans = ans * x % mod;

    exgcd(exgcd, max(in[t] - 1, 1ll), mod, x, y);
    x = (x % mod + mod) % mod;
    ans = ans * x % mod;

    // ans = ans * in[t] % mod;
    ans = ans * in[s] % mod;

    cout << ans << '\n';
  }

  return 0;
}