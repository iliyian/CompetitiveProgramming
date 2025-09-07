// date: 2025-07-24 10:00:03
// tag: 又是忘记处理变量导致的wa

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<std::vector<int>> pa(21, std::vector<int>(n + 1));
  auto dfs = [&](auto self, int u) -> void {
    for (int i = 1; i <= 20; i++) {
      pa[i][u] = pa[i - 1][pa[i - 1][u]];
    }
    for (int v : g[u]) {
      pa[0][v] = u;
      self(self, v);
    }
  };
  dfs(dfs, 1);
  std::vector<std::array<int, 3>> ask(k);
  for (auto &[u, l, r] : ask) {
    std::cin >> u >> l >> r;
  }
  auto get = [&](int x, int j) -> int {
    for (int i = 20; i >= 0; i--) {
      if (j >> i & 1) {
        x = pa[i][x];
      }
    }
    return x;
  };
  std::vector<int> vis(n + 1);
  vis[1] = vis[0] = 1;
  for (auto &[u, l, r] : ask) {
    if (vis[u]) {
      std::cout << l << '\n';
      return;
    }
    int dis = 0, uu = u;
    for (int i = 20; i >= 0; i--) {
      if (!vis[pa[i][u]]) {
        u = pa[i][u];
        dis += 1ll << i;
      }
    }
    dis++;
    if (dis <= r - l + 1) {
      std::cout << l + dis - 1 << '\n';
      return;
    }
    int v = get(uu, dis - (r - l + 1));
    while (!vis[v]) {
      vis[v] = 1;
      v = pa[0][v];
    }
  }
  std::cout << -1 << '\n';
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