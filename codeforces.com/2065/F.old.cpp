#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  // std::vector<std::set<int>> rev;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    // rev[a[i]].insert(i);
  }
  std::vector<int> ans(n + 1);
  std::vector<std::pair<int, int>> edges;
  std::vector<std::multiset<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    if (a[x] == a[y]) {
      ans[a[x]] = 1;
      continue;
    }
    g[x].insert(a[y]);
    g[y].insert(a[x]);
    edges.push_back({x, y});
  }
  for (auto [x, y] : edges) {
    // std::cerr << ans[2] << ' ';
    // std::cerr << x << ' ' << y << '\n';
    if (g[x].count(a[y]) >= 2) {
      ans[a[y]] = 1;
    }
    if (g[y].count(a[x]) >= 2) {
      ans[a[x]] = 1;
    }
    // std::cerr << ans[2] << ' ';
  }
  // std::cerr << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i];
  }
  std::cout << '\n';
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