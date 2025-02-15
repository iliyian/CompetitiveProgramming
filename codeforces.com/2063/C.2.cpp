#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  // std::vector<std::vector<int>> g(n + 1);
  std::vector<std::set<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].insert(y);
    g[y].insert(x);
    // g[x].push_back(y);
    // g[y].push_back(x);
  }
  if (n == 2) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = 0;
  // std::vector<int> f(n + 1);
  // auto dfs = [&](this auto &&self, int u, int p) -> void {
  //   int mx = 0;
  //   f[u] = g[u].size() - 1;
  //   for (int v : g[u]) {
  //     if (v != p) {
  //       self(v, u);
  //       ans = std::max<int>(ans, g[u].size() + g[v].size() - 2);
  //       mx = std::max(mx, f[v]);
  //     }
  //   }
  //   f[u] = std::max(f[u], mx);
  //   for (int v : g[u]) {
  //     if (v != p) {
  //       ans = std::max<int>(ans, g[p].size() + mx);
  //     }
  //   }
  //   // std::cout << u << ' ' << f[u] << '\n';
  // };
  // dfs(1, 0)
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans = std::max<int>(ans, g[i].size() + g[j].size() - (g[i].count(j) ? 2 : 1));
      // if (ans == 7) {
      //   std::cout << i << ' ' << j << '\n';
      // }
    }
  }
  std::cout << ans << '\n';
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