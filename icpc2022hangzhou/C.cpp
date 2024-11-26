// date: 2024-10-20 11:07:43
// tag: dp

#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("C.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<std::array<int, 2>>> f(n + 1, std::vector<std::array<int, 2>>(k + 1, std::array<int, 2>{INT_MIN, INT_MIN}));
  std::vector<std::vector<int>> w(n + 1, std::vector<int>(11));
  std::vector<int> p(n + 1);
  int sump = 0, maxw = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
    sump += p[i];
    for (int j = 1; j <= p[i]; j++) {
      std::cin >> w[i][j];
    }
    maxw += w[i][p[i]];
  }
  if (sump <= k) {
    std::cout << maxw << '\n';
    return 0;
  }
  f[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      f[i][j][0] = f[i - 1][j][0];
      f[i][j][1] = f[i - 1][j][1];
      if (j >= p[i]) {
        f[i][j][0] = std::max(f[i][j][0], f[i - 1][j - p[i]][0] + w[i][p[i]]);
        f[i][j][1] = std::max(f[i][j][1], f[i - 1][j - p[i]][1] + w[i][p[i]]);
      }
      for (int t = 1; t <= std::min(p[i] - 1, j); t++) {
        f[i][j][1] = std::max(f[i][j][1], f[i - 1][j - t][0] + w[i][t]);
      }
    }
  }
  std::cout << std::max(f[n][k][1], f[n][k][0]) << '\n';
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= k; j++) {
  //     std::cout << f[i][j][0] << '-' << f[i][j][1] << ' ';
  //   }
  //   std::cout << '\n';
  // }
  return 0;
}