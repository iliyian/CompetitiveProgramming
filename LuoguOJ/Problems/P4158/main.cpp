// date: 2024-08-15 10:49:45
// tag: 多维高复杂度dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m, t;
  std::cin >> n >> m >> t;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    for (int j = 0; j < m; j++) {
      a[i][j + 1] = a[i][j] + (str[j] == '1');
    }
  }
  std::vector g(n + 1,
                std::vector<std::vector<int>>(t + 1, std::vector<int>(m + 1)));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= t; j++) {
      for (int k = 1; k <= m; k++) {
        for (int q = 0; q < k; q++) {
          // [q + 1, k]
          g[i][j][k] =
              std::max(g[i][j][k],
                       g[i][j - 1][q] + std::max(a[i][k] - a[i][q],
                                                 k - q - (a[i][k] - a[i][q])));
        }
      }
    }
  }
  // 前i行共t次的最大值
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(t + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= t; j++) {
      f[i][j] = f[i - 1][j];
      for (int k = 0; k < j; k++) {
        f[i][j] = std::max(f[i][j], f[i - 1][k] + g[i][j - k][m]);
      }
    }
  }
  std::cout << f[n][t] << '\n';

  return 0;
}