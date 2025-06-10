// date: 2025-04-09 13:00:21
// tag: 比较少见但十分典型的dag上dp

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    int s;
    std::cin >> s;
    for (int j = 1; j <= s; j++) {
      int y, w;
      std::cin >> y >> w;
      g[i].push_back({y, w});
    }
  }
  std::vector<std::array<int, 3>> f(n + 1, {0, 0, 0});
  auto dfs = [&](auto self, int u, int p) -> void {
    for (auto [v, w] : g[u]) {
      if (v != p) {
        // std::cerr << w << ' ';
        f[u][w]++;
        f[u][w] %= mod;
        if (w == 0) {
          f[u][2] += f[u][1];
          f[u][2] %= mod;
        }
        if (!f[v][0] && !f[v][1]) {
          self(self, v, u);
        }
        f[u][2] += f[v][0] * f[u][1] % mod;
        f[u][2] %= mod;
        f[u][2] += f[v][2];
        f[u][2] %= mod;
        f[u][0] += f[v][0];
        f[u][0] %= mod;
        f[u][1] += f[v][1];
        f[u][1] %= mod;
      }
    }
    // std::cerr << f[u][0] << ' ' << f[u][1] << ' ' << f[u][2] << ' ' << u << '\n';
  };
  dfs(dfs, 1, 0);
  std::cout << f[1][2] << '\n';
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