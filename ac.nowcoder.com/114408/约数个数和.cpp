#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  // int r = 0;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= i; j++) {
  //     r += i % j == 0;
  //   }
  // }
  for (int l = 1, r = 1; l <= n; l = r + 1) {
    r = n / (n / l);
    ans += (r - l + 1) * (n / l);
    // std::cerr << l << ' ' << r << '\n';
  }
  // std::cout << ans << ' ' << r << '\n';
  std::cout << ans << '\n';
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