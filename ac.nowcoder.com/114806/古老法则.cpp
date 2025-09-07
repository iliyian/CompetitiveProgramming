#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, LLONG_MIN / 3));
  auto dfs = [&](auto self, int u, int p) -> void {
    f[u][0] = 0;
    if (b[u] <= m) {
      f[u][b[u]] = a[u];
    }
    // for (int i = b[u]; i <= m; i++) {
    //   f[u][i] = a[u];
    // }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        for (int i = m; i >= 0; i--) {
          for (int j = 0; j <= i - b[u]; j++) {
            f[u][i] = std::max(f[u][i], f[v][j] + f[u][i - j]);
          }
        }
      }
    }
  };
  dfs(dfs, 1, 0);
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    ans = std::max(ans, f[1][i]);
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     std::cerr << i << ' ' << j << ' ' << f[i][j] << '\n';
  //   }
  // }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}