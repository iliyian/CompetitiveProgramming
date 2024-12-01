#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<int> mn(n + 1, INT_MAX), mx(n + 1, INT_MIN);
  auto dfs = [&](auto self, int u) -> void {
    if (g[u].empty()) {
      mx[u] = mn[u] = 0;
      return;
    }
    for (int v : g[u]) {
      self(self, v);
      mn[u] = std::min(mn[v] + 1, mn[u]);
      mx[u] = std::max(mn[v] + 1, mx[u]);
    }
  };
  dfs(dfs, 1);
  int ans = *std::max_element(mx.begin() + 1, mx.end());
  ans = std::max(ans, mx[1]);
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
}