#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::vector<int>> up(21, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  std::vector<int> dep(n + 1), d(n + 1);
  auto dfs = [&](auto self, int u) -> void {
    for (int v : g[u]) {
      dep[v] = dep[u] + a[v];
      d[v] = d[u] + 1;
      up[0][v] = u;
      for (int i = 1; i <= 20; i++) {
        up[i][v] = up[i - 1][up[i - 1][v]];
      }
      self(self, v);
    }
  };
  dep[1] = a[1];
  d[1] = 1;
  dfs(dfs, 1);
  auto lca = [&](int x, int y) -> int {
    if (d[x] < d[y]) std::swap(x, y);
    for (int i = 20; i >= 0; i--) {
      if (d[up[i][x]] >= d[y]) {
        x = up[i][x];
      }
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
      if (up[i][x] != up[i][y]) {
        x = up[i][x], y = up[i][y];
      }
    }
    return up[0][x];
  };
  int q;
  std::cin >> q;
  while (q--) {
    int k;
    std::cin >> k;
    int x, y;
    std::cin >> x >> y;
    int z = lca(x, y);
    std::cout << dep[x] + dep[y] - dep[z] << '\n';
  }
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