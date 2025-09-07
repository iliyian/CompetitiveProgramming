#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> a(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x << 1 | 1].push_back()
  }
  std::queue<std::array<int, 4>> q;
  std::vector<std::array<std::array<int, 2>, 2>> dis(n + 1);
  for (int i = 1; i <= n; i++) {
    dis[i][0] = {-a[i], 0};
    dis[i][1] = {-a[i], 0};
  }
  for (int i = 1; i <= n; i++) {
    q.push({dis[i][0][0], dis[i][0][1], 0, i});
    q.push({dis[i][1][0], dis[i][1][1], 1, i});
  }
  while (!q.empty()) {
    auto [val, d, prv, u] = q.front(); q.pop();
    if (dis[u][prv] != std::array{val, d}) continue;
    for (auto [v, w] : g[u]) {
      int ww = (w != prv);
      if (dis[v][w] > std::array{val, d + ww}) {
        dis[v][w] = std::array{val, d + ww};
        q.push({dis[v][w][0], dis[v][w][1], w, v});
      }
    }
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