#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  int q;
  std::cin >> q;
  while (q--) {
    int s, t;
    std::cin >> s >> t;
    std::vector<int> dis(n + 1, LLONG_MAX / 3), prv(n + 1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    q.push({dis[s] = 0, s});
    while (!q.empty()) {
      auto [d, u] = q.top(); q.pop();
      if (dis[u] != d) continue;
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w) {
          prv[v] = u;
          q.push({dis[v] = dis[u] + w, v});
        }
      }
    }
    int u = t;
    while (u != s) {
      std::cout << u << ' ';
      u = prv[u];
    }
    std::cout << s << '\n';
    std::cout << (dis[t] == LLONG_MAX / 3 ? -1 : dis[t]) << '\n';
  }

  return 0;
}