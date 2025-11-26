#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, V, T;
  std::cin >> n >> m >> V >> T;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::vector<std::array<int, 2>> dis(n + 1, {LLONG_MAX / 3, LLONG_MAX / 3});
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
  dis[T] = {1, 0};
  q.push({1, 0, T});
  while (!q.empty()) {
    auto [nowb, nowv, u] = q.top(); q.pop();
    if (dis[u] != std::array{nowb, nowv}) continue;
    for (auto [v, w] : g[u]) {
      int bb = nowb, vv = nowv;
      if (nowv + w > V) {
        bb++, vv = w;
      } else {
        vv += w;
      }
      if (dis[v] > std::array{bb, vv}) {
        dis[v] = {bb, vv};
        q.push({bb, vv, v});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << (dis[i][0] == LLONG_MAX / 3 ? -1 : dis[i][0]) << ' ';
  }
  std::cout << '\n';
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