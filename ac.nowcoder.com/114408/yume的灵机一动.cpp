#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::array<int, 2>> f(n + 1, {0, 0});
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  auto dfs = [&](auto self, int u, int p) -> void {
    f[u][1] = a[u];
    if (u != 1 && g[u].size() == 2) {
      return;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
    int s = 0;
    for (int v : g[u]) {
      if (v != p) {
        f[u][1] += f[v][1];
        s += std::max(f[v][1], f[v][0]);
      }
    }
    for (int v : g[u]) {
      if (v != p) {
        f[u][0] = std::max(f[u][0], f[v][0] + s - std::max(f[v][1], f[v][0]));
      }
    }
  };
  dfs(dfs, 1, 0);
  std::cout << std::max(f[1][0], f[1][1]) << '\n';
  for (int i = 1; i <= n; i++) {
    std::cerr << f[i][0] << ' ' << f[i][1] << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;7

  while (t--) {
    solve();
  }

  return 0;
}