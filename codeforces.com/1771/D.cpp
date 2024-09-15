// date: 2024-09-14 13:16:12
// tag: 树形dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::vector<int>> pa(n + 1, std::vector<int>(n + 1)),
      f(n + 1, std::vector<int>(n + 1));
  auto dfs = [&](auto self, int u, int p, int rt) -> void {
    pa[rt][u] = p;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, rt);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    dfs(dfs, i, 0, i);
  }
  auto dfs2 = [&](auto self, int x, int y) -> int {
    if (x == y) return 1;
    if (x == pa[x][y] || y == pa[y][x]) return 1 + (str[x] == str[y]);
    if (x > y) std::swap(x, y);
    if (f[x][y]) return f[x][y];
    return f[x][y] =
        std::max({self(self, x, pa[x][y]),
                  self(self, pa[y][x], y),
                  self(self, pa[x][y], pa[y][x]) + 2 * (str[x] == str[y])});
  };
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans = std::max(ans, dfs2(dfs2, i, j));
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  freopen("D.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}