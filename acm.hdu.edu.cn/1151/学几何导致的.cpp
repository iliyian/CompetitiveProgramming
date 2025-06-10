#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  if (k % 2) {
    std::cout << 0 << '\n';
    return;
  }
  k /= 2;
  // 0 0 0 1 1 1 1 2
  int t = n / (4 * k);
  int ans = t * t * 4 * k;
  int rest = n % (4 * k);
  // std::cerr << rest << ' ' << 3 * k << ' ' << t << '\n';

  if (rest > 3 * k) {
    // ans += (rest - 3 * k) * (t * 2 + 1);
    ans += (rest - 3 * k) * (1);
  }
  // if (rest <= k) {
    ans += rest * t * 2;
  // }
  int cnt = std::max(0ll, rest - k);
  // std::cerr << cnt << '\n';
  ans += cnt * (1);

  std::cout << ans << '\n';
  return;

  // double prv = 0;
  // for (int i = 1; i <= n; i++) {
  //   double cur = prv + 180.0 / k;
  //   while (cur >= 360) cur -= 360;
  //   // if (std::abs(cur - 360) <= 1e-6 || cur <= 1e-6) {
  //   if (std::abs(cur - 90) <= 1e-6) {
  //     std::cerr << i << '\n';
  //   }
  //   std::cout << i << ' ' << cur << '\n';
  //   prv = cur;
  // }
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