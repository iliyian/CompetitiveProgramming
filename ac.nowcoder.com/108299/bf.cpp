#include <bits/stdc++.h>
#include <random>
#define int long long

std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::array<int, 3>>> g(n + 1);
  std::vector<std::array<int, 4>> e;
  std::vector<int> dis1(n + 1, LLONG_MAX / 3), dis2(n + 1, LLONG_MAX / 3);
  for (int i = 1; i <= m; i++) {
    int x, y, t, w;
    std::cin >> x >> y >> t >> w;
    if (x == y) continue;
    g[x].push_back({y, t, w});
  }
  auto dijkstra = [&](int s, int k) {
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>,
                        std::greater<>> q;
    std::vector<std::array<int, 2>> dis(n + 1, {LLONG_MAX / 3, LLONG_MAX / 3});
    q.push({dis[s][0] = 0, s, 0});
    while (!q.empty()) {
      auto [d, u, f] = q.top(); q.pop();
      if (dis[u][f] != d) continue;
      for (auto [v, t, w] : g[u]) {
        if (dis[v][f] > dis[u][f] + t) {
          q.push({dis[v][f] = dis[u][f] + t, v, f});
        }
        if (!f) {
          if (dis[v][1] > dis[u][0] + t - k * w) {
            q.push({dis[v][1] = dis[u][0] + t - k * w, v, 1});
          }
        }
      }
    }
    return dis[n][1];
  };
  int q;
  std::cin >> q;
  while (q--) {
    int k;
    std::cin >> k;
    std::cout << dijkstra(1, k) << '\n';
  }
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