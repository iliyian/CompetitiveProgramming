#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> in(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += g[i].empty();
  }
  // std::cout << cnt << '\n';
  std::cout << (cnt == 1 ? "Bob" : "Alice") << '\n';
  return;
  std::vector<int> f(n + 1), d(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        d[u] = std::max(d[u], d[v] + 1);
      }
    }
  };
  dfs(dfs, 1, 0);
  std::cout << (d[1] % 2 ? "Bob" : "Alice") << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}