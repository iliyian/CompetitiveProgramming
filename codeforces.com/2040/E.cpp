// date: 2024-12-11 20:57:38
// tag: 简单多状态的树形期望dp，根据多个可能的状态分别分类讨论即可，本题中为奇偶

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> siz(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    siz[i] = (g[i].size() - (i != 1));
  }
  //   auto dfs = [&](this auto &&self, int u, int p) -> void {
  //     siz[u] = g[u].size() - (p != 0);
  //     for (int v : g[u]) {
  //       if (v != p) {
  //         self(v, u);
  //         // siz[u] += siz[v];
  //       }
  //     }
  //   };
  // dfs(1, 0);
  std::vector<std::vector<std::array<int, 2>>> f(
      n + 1, std::vector<std::array<int, 2>>(n + 1, {INT_MAX, INT_MAX}));
  for (int i = 0; i <= n; i++) {
    f[1][i][0] = f[1][i][1] = 0;
  }
  auto dfs = [&](this auto &&self, int u, int pa, int p) -> void {
    for (int v : g[u]) {
      if (v != pa) {
        f[v][p][1] = 1 + f[u][p][0];
        f[v][p][0] = 1 + std::min((p ? f[u][p - 1][1] : INT_MAX), 2 * siz[v] + f[u][p][1]);
        self(v, u, p);
      }
    }
  };
  for (int i = 0; i <= n; i++) {
    dfs(1, 0, i);
  }
  while (q--) {
    int v, p;
    std::cin >> v >> p;
    std::cout << f[v][p][1] << ' ';
  }
  std::cout << '\n';
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