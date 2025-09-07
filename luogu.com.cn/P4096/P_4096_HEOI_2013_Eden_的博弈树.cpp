#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<std::array<int, 2>> f(n + 1, {0, 0});
  auto dfs = [&](auto self, int u, int d) -> void {
    if (g[u].empty())
    for (int v : g[u]) {
      self(self, v, d + 1);
      if (d % 2) {
        f[u][1] = std::min(f[u][1], f[v][1]);
        f[u][0] += f[v][0];
      } else {
        f[u][1] += f[v][1];
        f[u][0] = std::min(f[u][0], f[v][0]);
      }
    }
  };
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