// date: 2024-12-06 01:44:44
// tag: 树形dp，树上单一路径问题

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
  int ans = 0;
  std::vector<int> f(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    f[u] = g[u].size() - 2;
    int mx1 = 0, mx2 = 0;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        if (f[v] > mx1) {
          mx2 = mx1;
          mx1 = f[v];
        } else {
          mx2 = std::max(mx2, f[v]);
        }
        ans = std::max(f[u] + mx1 + 2, ans);
      }
    }
    ans = std::max(mx1 + mx2 + 2 + f[u], ans);
    f[u] += mx1;
  };
  dfs(dfs, 1, 0);
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