// date: 2025-04-21 00:50:43
// tag: 水的一批

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, c;
  std::cin >> n >> m >> c;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> siz(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = LLONG_MAX;
  auto dfs = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
    ans = std::min(ans, siz[u] * siz[u] + (n - siz[u]) * (n - siz[u]));
  };
  dfs(dfs, 1, 0);
  std::cout << ans << '\n';
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