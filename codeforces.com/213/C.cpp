// date: 2024-08-04 11:59:23
// tag: 空间优化dp

#include <bits/stdc++.h>
// #define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  std::vector f(n * 2, std::vector<std::vector<int>>(
                               n + 1, std::vector<int>(n + 1, INT_MIN)));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
  }

  f[0][1][1] = a[1][1];
  for (int i = 1; i <= n * 2 - 2; i++) {
    for (int x1 = 1; x1 <= n; x1++) {
      for (int x2 = 1; x2 <= n; x2++) {
        int y1 = i - x1 + 2, y2 = i - x2 + 2;
        if (y1 < 1 || y1 > n || y2 < 1 || y2 > n || x1 - 1 + y1 - 1 != i ||
            x2 - 1 + y2 - 1 != i) {
          continue;
        }
        int t = a[x1][y1] + a[x2][y2];
        if (x1 == x2) {
          t /= 2;
        }
        f[i][x1][x2] = std::max({f[i - 1][x1 - 1][x2 - 1], f[i - 1][x1][x2],
                                 f[i - 1][x1 - 1][x2], f[i - 1][x1][x2 - 1]}) +
                       t;
      }
    }
  }
  std::cout << f[n * 2 - 2][n][n] << '\n';

  return 0;
}