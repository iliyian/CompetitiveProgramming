// date: 2025-08-02 11:30:38
// tag: 虽然找不到wa的数据，但是就是得按照kruskal重构树的规则

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    std::vector<int> vis(n + 1);
    q.push({a[x], x});
    vis[x] = 1;
    while (!q.empty()) {
      auto [d, u] = q.top(); q.pop();
      if (y < d) break;
      y += b[u];
      for (int v : g[u]) {
        if (!vis[v]) {
          vis[v] = 1;
          q.push({a[v], v});
        }
      }
    }
    std::cout << y << '\n';
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