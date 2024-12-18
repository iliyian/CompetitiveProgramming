// date: 2024-12-18 20:59:26
// tag: 分层图折杀我也

#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e3;
constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::pair<int, int>>> g(N * 2 + 1);
  for (int i = 1; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y + N].push_back({x + N, w});
  }
  for (int i = 1; i <= N; i++) {
    g[i].push_back({i + N, 0});
  }
  std::vector<std::vector<int>> dis(N * 2 + 1, std::vector<int>(N * 2 + 1, inf));
  auto dijkstra = [&](int s) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    q.push({dis[s][s] = 0, s});
    while (!q.empty()) {
      auto [d, u] = q.top(); q.pop();
      if (dis[s][u] != d) continue;
      for (auto [v, w] : g[u]) {
        if (dis[s][v] > dis[s][u] + w) {
          dis[s][v] = dis[s][u] + w;
          q.push({dis[s][v], v});
        }
      }
    }
  };
  for (int i = 1; i <= N; i++) {
    dijkstra(i);
  }
  int m;
  std::cin >> m;
  std::vector<int> x(m + 1), y(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> x[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> y[i];
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      // std::cout << x[i] << ' ' << y[j] << ' ';
      // std::cout << dis[x[i]][y[j] + N] << '\n';
      if (dis[x[i]][y[j] + N] == inf) {
        std::cout << -1 << '\n';
        return;
      }
      ans += dis[x[i]][y[j] + N];
    }
  }
  std::cout << ans << '\n';
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