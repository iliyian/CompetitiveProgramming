// date: 2024-05-08 15:19:55
// tag: hld

#include <bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G2.in", "r", stdin);
  freopen("G2.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  bitset<N + 5> vis;

  vector<int> dep(n + 1), siz(n + 1), son(n + 1), dfn(n + 1), rnk(n + 1), pa(n + 1), top(n + 1);
  vector<int> d(n + 1), tag(n + 1);
  int tot = 0, T = 0;
  auto dfs = [&](auto self, int u) -> void {
    dep[u] = dep[pa[u]] + 1;
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != pa[u]) {
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
    dfn[u] = ++tot;
    rnk[tot] = u;
    top[u] = t;
    if (!son[u]) return;
    self(self, son[u], t);
    for (int v : g[u]) {
      if (v != pa[u] && v != son[u]) {
        self(self, v, v);
      }
    }
  };
  dfs(dfs, 1);
  dfs2(dfs2, 1, 1);

  auto lca = [&](int x, int y) {
    while (top[x] != top[y]) {
      if (dep[top[x]] < dep[top[y]]) swap(x, y);
      x = pa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
  };

  auto sum = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      if (tag[i] == T) {
        ans += d[i];
      }
    }
    return ans;
  };

  auto add = [&](int x) {
    for (int i = x; i <= n; i += i & -i) {
      if (tag[i] != T) d[i] = 0;
      d[i]++, tag[i] = T;
    }
  };

  auto hldsum = [&](int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
      if (dep[top[x]] < dep[top[y]]) swap(x, y);
      ans += sum(dfn[x]) - sum(dfn[top[x]] - 1);
      x = pa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    ans += sum(dfn[x]) - sum(dfn[y] - 1);
    return ans;
  };

  int q;
  cin >> q;
  for (int _ = 1; _ <= q; _++) {
    int k;
    cin >> k;
    vector<int> p(k + 1);
    vis.reset();
    int r = 0;
    T = _;
    for (int i = 1; i <= k; i++) {
      cin >> p[i];
      if (dep[p[i]] > dep[r]) r = p[i];
      vis[p[i]] = true;
      add(dfn[p[i]]);
    }

    int l = 0;
    for (int i = 1; i <= k; i++) {
      if (dep[p[i]] > dep[l] && lca(p[i], r) != p[i]) {
        l = p[i];
      }
    }

    int lc = lca(l, r);
    int cnt = hldsum(lc, l) + hldsum(lc, r) - vis[lc];

    cout << (!l || cnt == k ? "YES" : "NO") << '\n';
  }

  return 0;
}