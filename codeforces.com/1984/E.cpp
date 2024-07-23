// date: 2024-07-23 13:29:40
// tag: 最大独立集，树形dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::array<std::array<int, 2>, 2>> f(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    f[u][0][1] = f[u][1][1] = 1;
    int mx0 = 0, mx1 = 0;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        f[u][0][0] += std::max(f[v][0][0], f[v][0][1]);
        f[u][0][1] += f[v][0][0];
        mx0 = std::max(mx0, std::max(f[v][1][0], f[v][1][1]) - std::max(f[v][0][0], f[v][0][1]));
        mx1 = std::max(mx1, f[v][1][0] - f[v][0][0]);
        if (g[v].size() == 1) {
          mx1 = std::max(mx1, 1ll);
        }
      }
    }
    f[u][1][0] = f[u][0][0] + mx0;
    f[u][1][1] = f[u][0][1] + mx1;
  };
  if (n == 2) {
    std::cout << 2 << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size() > 1) {
      dfs(dfs, i, 0);
      int ans = std::max({f[i][0][0], f[i][0][1], f[i][1][0], f[i][1][1]});
      std::cout << ans << '\n';
      return;
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}