// date: 2025-01-30 14:16:45
// tag: 基于最远互质数间隔很小的数论结论的暴力
// 虽然我还是不确定为什么第一步就是对的

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  int aa = n, bb = n;
  while (std::gcd(aa, a) != 1) aa--;
  while (std::gcd(bb, b) != 1) bb--;
  int ans = bb - 1 + aa - 1;
  for (int i = 1; i <= aa; i++) {
    ans += std::gcd(i, a);
  }
  for (int i = 1; i <= bb; i++) {
    ans += std::gcd(i, b);
  }
  std::vector<std::vector<int>> f(n - aa + 2, std::vector<int>(n - bb + 2, INT_MAX));
  ans -= 2;
  // for (int i = 0; i <= n - aa + 1; i++) {
  //   f[i][0] = 0;
  // }
  // for (int i = 0; i <= n - bb + 1; i++) {
  //   f[0][i] = 0;
  // }
  f[0][1] = f[1][0] = 0;
  // std::cerr << aa << ' ' << bb << '\n';
  // std::cerr << ans << '\n';
  ans = std::max(ans, 0ll);
  for (int i = aa; i <= n; i++) {
    for (int j = bb; j <= n; j++) {
      auto x = i - aa + 1, y = j - bb + 1;
      f[x][y] = std::min(f[x - 1][y], f[x][y - 1]) + std::gcd(i, a) + std::gcd(b, j);
      // std::cerr << f[x][y] << ' ';
    }
    // std::cerr << '\n';
  }
  std::cout << f[n - aa + 1][n - bb + 1] + ans << '\n';
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