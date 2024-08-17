// date: 2024-08-13 15:25:41
// tag: 判断到点集中任意点距离最大值，树形dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, m, d;
  std::cin >> n >> m >> d;
  std::vector<int> isp(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x;
    isp[x] = true;
  }
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  // 最大值不具有局部性
  std::vector<std::array<int, 3>> f(n + 1, {INT_MIN, INT_MIN, INT_MIN});
  auto dfs = [&](auto self, int u, int p) -> void {
    if (isp[u]) {
      f[u][1] = f[u][2] = 0;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        if (f[v][1] + 1 > f[u][1]) {
          f[u][2] = f[u][1];
          f[u][1] = f[v][1] + 1;
        } else if (f[v][1] + 1 > f[u][2]) {
          f[u][2] = f[v][1] + 1;
        }
      }
    }
  };
  dfs(dfs, 1, 0);

  auto dfs2 = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        if (f[u][1] == f[v][1] + 1) {
          f[v][0] = std::max(f[u][0] + 1, f[u][2] + 1);
        } else {
          f[v][0] = std::max(f[u][1] + 1, f[u][0] + 1);
        }
        self(self, v, u);
      }
    }
  };
  dfs2(dfs2, 1, 0);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += std::max(f[i][1], f[i][0]) <= d;
  }
  std::cout << ans << '\n';

  return 0;
}