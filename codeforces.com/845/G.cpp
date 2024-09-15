// date: 2024-09-12 12:30:01
// tag: 图上线性基

#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("G.in", "r", stdin);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::vector<int> vis(n + 1), res(n + 1);
  std::vector<int> d(63);
  auto insert = [&](int x) {
    for (int i = 62; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i]) {
          x ^= d[i];
        } else {
          d[i] = x;
          return;
        }
      }
    }
  };
  auto dfs = [&](auto self, int u, int x) -> void {
    vis[u] = true;
    res[u] = x;
    for (auto &[v, w] : g[u]) {
      if (!vis[v]) {
        self(self, v, x ^ w);
      } else {
        insert(x ^ w ^ res[v]);
      }
    }
  };
  dfs(dfs, 1, 0);
  int ans = res[n];
  for (int i = 62; i >= 0; i--) {
    if ((ans ^ d[i]) < ans) {
      ans ^= d[i];
    }
  }
  std::cout << ans << '\n';
  return 0;
}