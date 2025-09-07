#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::vector<int>> pa(21, std::vector<int>(n + 1));
  std::vector<int> dep(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    pa[0][u] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i <= 20; i++) {
      pa[i][u] = pa[i - 1][pa[i - 1][u]];
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, n, 0);
  int ans = 0, now = 1;
  auto lca = [&](int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 20; i >= 0; i--) {
      if (dep[pa[i][x]] >= dep[y]) {
        x = pa[i][x];
      }
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
      if (pa[i][x] != pa[i][y]) {
        x = pa[i][x], y = pa[i][y];
      }
    }
    return pa[0][x];
  };
  for (int i = 1; i <= n; i++) {
    now = lca(now, i);
    ans += dep[now];
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}