#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> dis(n + 1, LLONG_MAX / 3);
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  q.push({dis[1] = 0, 1});
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    if (dis[u] != d) continue;
    for (auto [v, w] : g[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i] * dis[i];
  }
  std::cout << ans << '\n';
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