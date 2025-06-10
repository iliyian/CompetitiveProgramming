#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, x;
  std::cin >> n >> m >> x;
  std::vector<std::vector<std::pair<int, int>>> g(n * 2 + 1);
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    g[i].push_back({a[i] + n, x});
    g[a[i] + n].push_back({i, 0});
  }
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
  }
  std::vector<std::array<int, 3>> dis(n * 2 + 1, {LLONG_MAX / 3, LLONG_MAX / 3, LLONG_MAX / 3});
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
  q.push({dis[1][0] = 0, 1, 0});
  std::vector<std::array<int, 3>> prv(n * 2 + 1);
  while (!q.empty()) {
    auto [d, u, e] = q.top(); q.pop();
    if (dis[u][e] != d) continue;
    for (auto [v, w] : g[u]) {
      bool f = (u <= n);
      if (dis[v][(e + f) % 3] > dis[u][e] + w) {
        dis[v][(e + f) % 3] = dis[u][e] + w;
        // prv[v][(e + f) % 3] = u;
        q.push({dis[v][(e + f) % 3], v, (e + f) % 3});
      }
    }
  }
  std::cout << (dis[n][0] == LLONG_MAX / 3 ? -1 : dis[n][0]) << '\n';
  // int u = n, e = 0;
  // while (u != 1) {
  //   std::cout << u << ' ' << e << '\n';
  //   u = prv[u][e];
  //   if (u <= n) e = (e + 2) % 3;
  // }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}