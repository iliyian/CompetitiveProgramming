// date: 2024-08-15 10:02:53
// tag: 最短路优化dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m, k, e;
  std::cin >> n >> m >> k >> e;
  std::vector<std::vector<std::pair<int, int>>> g(m + 1);
  for (int i = 1; i <= e; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  int d;
  std::cin >> d;
  std::vector<int> seal(m + 1);
  std::vector<std::vector<int>> off(n + 1);
  for (int i = 1; i <= d; i++) {
    int p, a, b;
    std::cin >> p >> a >> b;
    for (int j = a; j <= b; j++) {
      off[j].push_back(p);
    }
  }
  std::vector<int> dis(m + 1, -1);
  auto dijkstra = [&]() {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    std::fill(dis.begin() + 1, dis.end(), -1);
    q.push({0, 1});
    while (!q.empty()) {
      auto [d, u] = q.top(); q.pop();
      if (dis[u] != -1 || seal[u]) continue;
      dis[u] = d;
      for (auto [v, w] : g[u]) {
        q.push({d + w, v});
      }
    }
    return dis[m];
  };
  std::vector<std::vector<int>> cost(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      std::fill(seal.begin(), seal.end(), 0);
      for (int k = i; k <= j; k++) {
        for (auto p : off[k]) {
          seal[p] = true;
        }
      }
      cost[i][j] = dijkstra();
      if (cost[i][j] == -1) {
        cost[i][j] = INT_MAX;
      }
    }
  }

  std::vector<int> f(n + 1, INT_MAX);
  for (int i = 1; i <= n; i++) {
    f[i] = cost[1][i] * i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      f[i] = std::min(f[i], f[j] + cost[j + 1][i] * (i - j) + k);
    }
  }
  std::cout << f[n] << '\n';
  return 0;
}