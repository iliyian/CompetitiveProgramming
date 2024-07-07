// date: 2024-07-02 19:32:05
// tag: 二维卷积，二位前缀和，暴力

#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  int n, m, k, l;
  std::cin >> n >> m >> k >> l;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] += a[i][j - 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      a[i][j] += a[i - 1][j];
    }
  }
  std::vector<std::vector<int>> K(k + 1, std::vector<int>(l + 1));
  int ans = 0;
  for (int i = n - k + 1; i <= n; i++) {
    for (int j = m - l + 1; j <= m; j++) {
      int sum = a[i][j] - a[i - (n - k + 1)][j] - a[i][j - (m - l + 1)] + a[i - (n - k + 1)][j - (m - l + 1)];
      K[i - n + k][j - m + l] = (sum > 0 ? 1 : sum == 0 ? 0 : -1);
      ans += sum * K[i - n + k][j - m + l];
    }
  }

  // for (int i = 1; i <= n - k + 1; i++) {
  //   for (int j = 1; j <= m - l + 1; j++) {
  //     int sum = 0;
  //     for (int x = 1; x <= k; x++) {
  //       for (int y = 1; y <= l; y++) {
  //         int xx = i + x - 1, yy = j + y - 1;
  //         sum += (a[xx][yy] - a[xx - 1][yy] - a[xx][yy - 1] + a[xx - 1][yy - 1]) * K[x][y];
  //       }
  //     }
  //     std::cout << sum << ' ';
  //   }
  //   std::cout << '\n';
  // }


  // for (int i = 1; i <= k; i++) {
  //   for (int j = 1; j <= l; j++) {
  //     std::cout << K[i][j] << ' ';
  //   }
  //   std::cout << '\n';
  // }
  std::cout << ans << '\n';

  return 0;
}