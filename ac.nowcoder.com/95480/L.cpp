#include <bits/stdc++.h>
#define int long long

constexpr int N = 2000;
constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int t;
  std::cin >> t;
  std::vector<int> a(t + 1), b(t + 1), c(t + 1);
  std::vector<std::vector<std::pair<int, int>>> g(N + 1);
  for (int i = 1; i <= t; i++) {
    std::cin >> a[i] >> b[i] >> c[i];
    g[b[i]].push_back({a[i], c[i]});
  }
  std::vector<std::vector<int>> dis(N + 1, std::vector<int>(N + 1, inf));
  // std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
  std::queue<std::array<int, 3>> q;
  for (int i = 1; i <= N; i++) {
    q.push({dis[i][i] = 0, i, i});
  }
  while (!q.empty()) {
    // auto [d, x, y] = q.top(); q.pop();
    auto [d, x, y] = q.front(); q.pop();
    if (dis[x][y] != d) continue;
    for (auto [v, w] : g[x]) {
      if (dis[v][y] > dis[x][y] + w) {
        dis[v][y] = dis[x][y] + w;
        q.push({dis[v][y], v, y});
      }
    }
    for (auto [v, w] : g[y]) {
      if (dis[x][v] > dis[x][y] + w) {
        dis[x][v] = dis[x][y] + w;
        q.push({dis[x][v], x, v});
      }
    }
  }
  int n;
  std::cin >> n;
  std::vector<int> x(n + 1), y(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> y[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dis[x[i]][y[j]] == inf) {
        std::cout << -1 << '\n';
        return;
      }
      ans += dis[x[i]][y[j]];
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