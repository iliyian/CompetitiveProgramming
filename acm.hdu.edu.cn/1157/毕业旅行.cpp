#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, x;
  std::cin >> n >> m >> x;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, std::greater<>> q;
  std::vector<std::array<int, 2>> dis1(n + 1), dis2(n + 1); // dis优先和cnt优先
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    for (auto [v, w] : g[u]) {
      
    }
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