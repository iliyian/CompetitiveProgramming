#include <bits/stdc++.h>
#include <functional>
#include <queue>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(n + 1);
  std::vector<std::vector<std::pair<int, int>>> g(n * 2+ 1);

  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    g[i].push_back({i + n, a[i]});
  }

  for (int i = 1; i <= m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    g[u + n].push_back({v, w});
    g[v + n].push_back({u, w});
  }

  std::vector<int> dis(n * 2 + 1, -1);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
  q.push({0, 1});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (dis[u] != -1) continue;
    dis[u] = d;
    for (auto [v, w] : g[u]) {
      q.push({dis[u] + w, v});
    }
  }

  for (int i = 2; i <= n; i++) {
    std::cout << dis[i + n] << ' ';
  }

  return 0;
}