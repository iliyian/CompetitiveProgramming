// date: 2024-07-26 14:33:14
// tag: 树，贪心，暴力

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> pa(n + 1);
  vector<int> dep(n + 1);
  int tot = 0, maxd = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    if (dep[u] > dep[maxd]) {
      maxd = u;
    }
    for (int v : g[u]) {
      if (v != p) {
        pa[v] = u;
        self(self, v, u);
      }
    }
  };
  auto p = [&](int x, int d) -> int {
    while (d--) {
      x = pa[x];
    }
    return x;
  };
  dfs(dfs, 1, 0);
  auto lca = [&](int x, int y) {
    while (dep[x] != dep[y]) {
      if (dep[x] < dep[y]) std::swap(x, y);
      x = pa[x];
    }
    if (x == y) return x;
    while (pa[x] != pa[y]) {
      x = pa[x], y = pa[y];
    }
    return pa[x];
  };
  int _lca = lca(x, y);
  int dis = dep[x] + dep[y] - dep[_lca] * 2;
  int z = 0, ans = 2 * (n - 1) + (dis + 1) / 2;
  if (dis % 2 == 0) {
    z = p(dep[x] > dep[y] ? x : y, dis / 2);
  } else {
    z = (dep[x] > dep[y] ? p(x, dis / 2) : p(y, dis / 2 + 1));
  }
  dep[z] = 1;
  maxd = 0;
  dfs(dfs, z, 0);
  ans -= dep[maxd] - dep[z];
  std::cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}