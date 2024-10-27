#include <bits/stdc++.h>
#include <iomanip>

signed main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += 1.0 / i * n;
    }
    std::cout << std::fixed << std::setprecision(20) << ans << '\n';
  }
}