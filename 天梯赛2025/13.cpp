#include <bits/stdc++.h>
#define int long long

void solve() {
  int b, n, m, k;
  std::cin >> b >> n >> m >> k;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1, std::vector<std::pair<int, int>>(n + 1, {LLONG_MAX / 3, LLONG_MIN / 3}));
  for (int i = 1; i <= n; i++) {
    g[i][i] = {0, 0};
  }
  for (int i = 1; i <= m; i++) {
    int x, y, w, v;
    std::cin >> x >> y >> w >> v;
    g[x][y] = {w, v};
  }
  for (int t = 1; t <= n; t++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        auto w = g[i][k].first + g[k][j].first;
        if (w <= g[i][j].first) {
          g[i][j].first = w;
          if (w < g[i][j].first) {
            g[i][j].second = g[i][k].second + g[k][j].second;
          } else {
            g[i][j].second = std::max(g[i][j].second, g[i][k].second + g[k][j].second);
          }
        }
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    int x;
    std::cin >> x;
    int mn = LLONG_MAX / 3;
    int mxv = LLONG_MIN / 3;
    for (int y = 1; y <= n; y++) {
      if (y == x) continue;
      auto [w, v] = g[x][y];
      if (w < mn) {
        mn = w;
        mxv = v;
      }
    }
    for (int y = 1; y <= n; y++) {
      if (y == x) continue;
      auto [w, v] = g[x][y];
      if (w == mn && v == mxv) {
        std::cout << y << ' ';
      }
    }
    std::cout << '\n';
  }
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