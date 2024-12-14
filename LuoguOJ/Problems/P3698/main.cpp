// date: 2024-12-13 23:38:30
// tag: 树上非简单路径，树上遍历时每条边恰好走两次之类的性质？贪心，可dp
// 树上经过所有点的回路每条边恰好走两次

#include <bits/stdc++.h>
#define int long long

signed main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    x++, y++;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int maxdep = 0;
  std::vector<int> dep(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    maxdep = std::max(maxdep, dep[u]);
    for (int v : g[u]) {
      if (v != p) {
        dep[v] = dep[u] + 1;
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  if (m <= maxdep) {
    std::cout << m + 1 << '\n';
  } else {
    std::cout << std::min(n, (maxdep + 1 + (m - maxdep) / 2)) << '\n';
  }
  return 0;
}