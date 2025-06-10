// date: 2025-04-17 21:19:23
// tag: 比较新奇的基于值域的区间dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    pos[a[i]] = i;
  }
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, LLONG_MAX / 3));
  for (int i = 1; i <= n; i++) {
    f[i][i] = 0;
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      for (int i = l; i < r; i++) {
        f[l][r] = std::min(f[l][r],  f[l][i] + f[i + 1][r] + std::abs(pos[i + 1] - pos[l]));
        // if (l == 3 && r == 8) {
        //   std::cout << l << ' ' << i << ' ' << r << ' ' << f[l][i] << ' ' << f[i + 1][r] << ' ' << f[l][r] << '\n';
        // }
      }
    }
  }
  for (int l = 1; l <= n; l++) {
    for (int r = l + 1; r <= n; r++) {
      // std::cout << l << ' ' << r << ' ' << f[l][r] << '\n';
    }
  }
  std::cout << f[1][n] << '\n';
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