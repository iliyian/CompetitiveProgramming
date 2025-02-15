// date: 2025-01-24 20:37:25
// tag: dp

#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m));
  std::vector<std::vector<std::vector<int>>> f(n + 1, std::vector<std::vector<int>>(m, std::vector<int>(m, inf)));
  for (int i = 0; i < m; i++) {

    // for (int j = 0; j < m; j++) {
      f[0][0][i] = 0;
    // }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
    }
  }
  // 到达第i行第j个且第i行转了k次后的最小值
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      int mn = inf;
      for (int x = 0; x < m; x++) {
        mn = std::min(mn, f[i - 1][j][x]);
      }
      // std::cerr << std::format("mn({},{}):{}", i, j + 1, mn) << '\n';
      for (int x = 0; x < m; x++) {
        f[i][j][x] = std::min(mn + k * x, (j ? f[i][j - 1][x] : inf)) + a[i][(j + x) % m];
        // std::cerr << std::format("f({},{},{}):{}", i, j + 1, x, f[i][j][x]) << '\n';
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < m; i++) {
    // std::cerr << std::format("({},{},{}):{}", n, m - 1 + 1, i, f[n][m - 1][i]) << '\n';
    ans = std::min(ans, f[n][m - 1][i]);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}