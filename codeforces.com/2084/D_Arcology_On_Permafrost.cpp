#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  auto check = [&](int mid) -> bool {
    int t = n / mid;
    int len = (t - 1) * mid + 1 + n % mid;
    return n / mid > m && k * m < len;
  };
  int l = 1, r = 3e5, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  // std::cerr << ans << '\n';
  // if (ans == 1) {
  //   for (int i = 1; i <= n; i++) {
  //     std::cout << 0 << ' ';
  //   }
  //   std::cout << '\n';
  //   return;
  // }
  for (int i = 0; i < n; i++) {
    if (ans > k) {
      std::cout << i % ans << ' ';
    } else {
      std::cout << std::min(ans, i % k) << ' ';
    }
    // if (i == n - 1) {
    //   std::cout << ans - 1 << ' ';
    // } else {
    //   std::cout << i % (ans) << ' ';
    // }
  }
  std::cout << '\n';
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