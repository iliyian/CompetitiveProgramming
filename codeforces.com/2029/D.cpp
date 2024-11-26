#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::set<int>> g(n + 1);
  int cnt = 0;
  std::vector<std::pair<int, int>> edges(m + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    if (x > y) std::swap(x, y);
    edges[i] = {x, y};
    g[x].insert(y);
    g[y].insert(x);
  }
  std::vector<std::array<int, 3>> ans;
  for (int i = 1; i <= n; i++) {
    while (g[i].size() > 1) {
      int x = *g[i].begin(); g[i].erase(g[i].begin());
      int y = *g[i].begin(); g[i].erase(g[i].begin());
      if (g[x].contains(y)) {
        g[x].erase(g[x].find(y));
        g[y].erase(g[y].find(x));
      }
      ans.push_back({i, x, y});
    }
    if (g[i].size() == 1) {
      
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}