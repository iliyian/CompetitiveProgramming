#include <bits/stdc++.h>
#define int long long

constexpr int inf = LLONG_MAX / 3;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("F.in", "r", stdin);
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<std::array<int, 3>> edges(m + 1);
  for (int i = 1; i <= m; i++) {
    auto &[x, y, w] = edges[i];
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1, inf));
  auto bfs = [&](int s) -> void {
    std::queue<std::pair<int, int>> q;
    q.push({s, 0});
    dis[s][s] = 0;
    while (!q.empty()) {
      auto [u, d] = q.front(); q.pop();
      for (auto &[v, w] : g[u]) {
        if (dis[s][v] < d + w) continue;
        dis[s][u] = d + w;
        q.push({v, d + w});
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    bfs(i);
  }
  while (q--) {
    int op, x, y;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x;
      auto [u, v, w] = edges[x];
      edges[x][2] = inf;
      g[u].erase(std::find(g[u].begin(), g[u].end(), std::pair{v, w}));
      g[v].erase(std::find(g[v].begin(), g[v].end(), std::pair{u, w}));
      for (auto &v : dis) {
        std::fill(v.begin(), v.end(), inf);
      }
      for (int i = 1; i <= n; i++) {
        bfs(i);
      }
    } else {
      std::cin >> x >> y;
      std::cout << (dis[x][y] == inf ? -1 : dis[x][y]) << '\n';
    }
  }
  return 0;
}