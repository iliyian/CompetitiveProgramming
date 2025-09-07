#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<int> dis(n + 1);
  std::vector<std::pair<int, std::vector<int>>> b(n + 1);
  for (int i = 1; i <= k; i++) {
    int t, sc;
    std::cin >> t >> sc;
    b.push_back({t, {}});
    for (int j = 1; j <= sc; j++) {
      int x;
      std::cin >> x;
      b.back().second.push_back(x);
    }
  }
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
  }
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    for (auto [v, w] : g[u]) {
      
    }
  }
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