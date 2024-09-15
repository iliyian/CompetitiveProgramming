// date: 2024-09-14 16:20:39
// tag: 树形dp

#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("D.in", "r", stdin);
  // auto start = std::chrono::high_resolution_clock::now();
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(k + 1)),
      h(n + 1, std::vector<int>(k + 1));
  for (int i = 1; i <= n; i++) {
    f[i][0] = h[i][1] = 1;
  }
  h[1][1] = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        for (int i = 1; i <= k; i++) {
          f[u][i] += f[v][i - 1];
        }
      }
    }
  };
  dfs(dfs, 1, 0);
  
  auto dfs2 = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        for (int i = 2; i <= k; i++) {
          h[v][i] = h[u][i - 1] + f[u][i - 1] - f[v][i - 2];
        }
        self(self, v, u);
      }
    }
  };
  dfs2(dfs2, 1, 0);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += f[i][k] + h[i][k];
  }
  ans /= 2;
  std::cout << ans << '\n';

  // auto end = std::chrono::high_resolution_clock::now();
  // std::cout << std::chrono::duration<double, std::milli>(end - start) << '\n';

  return 0;
}