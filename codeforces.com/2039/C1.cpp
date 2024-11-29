#include <bits/stdc++.h>
#define int long long

void solve() {
  int x, m;
  std::cin >> x >> m;
  int l = 1, r = m, ans1 = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (((mid * x) ^ x) <= m) l = mid + 1, ans1 = mid;
    else r = mid - 1;
  }
  if (m % x == 0) ans1 = m / x;
  // std::cout << ans1;
  std::cout << x << ": ";
  for (int y = 1; y <= m; y++) {
    int t = x ^ y;
    if (t % y == 0) {
      // std::cout << y << ' ';
      std::cout << t / y - 1 << ' ';
      // assert(x == y);
    }
  }
  std::cout << '\n';
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