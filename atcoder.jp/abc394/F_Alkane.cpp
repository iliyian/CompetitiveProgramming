// date: 2025-02-27 21:57:18
// tag: 比较新奇的树形dp定义，按照三叉树的角度

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> f(n + 1, 1);
  int ans = -1;
  auto dfs = [&](auto self, int u, int p) -> void {
    // std::cerr << u << '\n';
    std::multiset<int> s;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        s.insert(f[v]);
        if (s.size() > 4) s.erase(s.begin());
      }
    }
    if (g[u].size() < 4) return;
    int t = 3;
    for (int i : s | std::views::reverse) {
      if (!t--) break;
      f[u] += i;
    }
    if (p == 0 && g[u].size() >= 4 || g[u].size() >= 5) {
      ans = std::max(ans, f[u] + *s.begin());
    }
    ans = std::max(ans, f[u] + 1);
  };
  dfs(dfs, 1, 0);
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << f[i] << " \n"[i == n];
  // }
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