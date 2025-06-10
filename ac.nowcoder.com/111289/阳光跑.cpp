#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  while (q--) {
    int x, k;
    std::cin >> x >> k;
    std::queue<std::pair<int, int>> q;
    q.push({0, x});
    std::set<int> s;
    while (!q.empty()) {
      auto [d, u] = q.front(); q.pop();
      if (d == k) {
        s.insert(u);
        continue;
      }
      for (int v : g[u]) {
        q.push({d + 1, v});
      }
    } 
    std::cout << s.size() << ' ';
    for (int i : s) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
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