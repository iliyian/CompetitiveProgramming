#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::vector<int>> pa(20, std::vector<int>(n + 1));
  std::vector<int> dep(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    pa[0][u] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i < 20; i++) {
      pa[i][u] = pa[i - 1][pa[i - 1][u]];
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  auto lca = [&](int x, int y) -> int {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 19; i >= 0; i--) {
      if (dep[x] - (1 << i) >= dep[y]) {
        x = pa[i][x];
      }
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; i--) {
      if (pa[i][x] != pa[i][y]) {
        x = pa[i][x], y = pa[i][y];
      }
    }
    return pa[0][x];
  };
  std::vector<int> b(n + 1), c(k + 1);
  std::vector<int> vis(n + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> c[i];
    b[c[i]] = 1;
    vis[c[i]] = 1;
  }
  int lc = lca(c[1], c[2]);
  for (int i = 3; i <= k; i++) {
    lc = lca(lc, c[i]);
  }
  // std::cout << lc << '\n';
  for (int i = 1; i <= k; i++) {
    int x = c[i];
    x = pa[0][x];
    while (x > 0 && !vis[x]) {
      vis[x] = 1;
      x = pa[0][x];
    }
  }
  std::cout << std::count(vis.begin() + 1, vis.end(), 1) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}