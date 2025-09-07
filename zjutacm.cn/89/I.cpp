#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<std::pair<int, int>>> g(n * 2 + 1);
  for (int i = 1; i <= k; i++) {
    int x;
    std::cin >> x;
    g[x].push_back({x + n, 0});
    g[x + n].push_back({x, 0});
  }
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
    g[x + n].push_back({y + n, w ^ 1});
    g[y + n].push_back({x + n, w ^ 1});
  }
  std::vector<int> dis(n * 2 + 1, LLONG_MAX / 3);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  q.push({dis[1] = 0, 1});
  while (!q.empty()) {
    auto val = q.top(); q.pop();
    int d = val.first, u = val.second;
    if (dis[u] != d) continue;
    for (auto vv : g[u]) {
      int v = vv.first, w = vv.second;
      if (dis[v] > dis[u] + w) {
        q.push({dis[v] = dis[u] + w, v});
      }
    }
  }
  std::cout << dis[n] << '\n';
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