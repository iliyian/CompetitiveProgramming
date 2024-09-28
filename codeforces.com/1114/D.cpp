// date: 2024-09-18 23:07:46
// tag: 记忆化搜索实现的dp，单点扩展型区间dp

#include <bits/stdc++.h>
// #define int long long

signed main() {
  freopen("D.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);

  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<std::array<int, 2>>> f(n + 1, std::vector<std::array<int, 2>>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = {i == j ? 0 : INT_MAX, i == j ? 0 : INT_MAX};
    }
  }

  for (int r = 1; r <= n; r++) {
    for (int l = r - 1; l >= 1; l--) {
      f[l][r][0] = std::min(
        f[l + 1][r][0] + (a[l] != a[l + 1]),
        f[l + 1][r][1] + (a[l] != a[r])
      );
      f[l][r][1] = std::min(
        f[l][r - 1][0] + (a[r] != a[l]),
        f[l][r - 1][1] + (a[r] != a[r - 1])
      );
    }
  }
  std::cout << std::min(f[1][n][0], f[1][n][1]) << '\n';

  return 0;
}