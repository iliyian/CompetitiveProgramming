// date: 2024-11-29 21:35:03
// tag: 位运算，异或性质

#include <bits/stdc++.h>
#define int long long

void solve() {
  int x, m;
  std::cin >> x >> m;
  int ans = 0;
  for (int y = 1; y <= std::min(m, x); y++) {
    int t = x ^ y;
    if (t % y == 0) {
      ans++;
    }
  }
  // x ^ kx == y, x ^ kx <= (k + 1)x = m
  // x ^ kx >= kx - x > m
  ans += m / x - 1;
  for (int k = m / x; k * x - x <= m; k++) {
    int t = (k * x) ^ x;
    if (t <= m) {
      ans++;
    }
  }
  if (m >= x) ans--;
  // int real = 0;
  // for (int y = 1; y <= m; y++) {
  //   int t = x ^ y;
  //   real += (t % x == 0 || t % y == 0);
  // }
  // std::cout << ans << ' ' << real << '\n';
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}