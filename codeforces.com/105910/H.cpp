#include <bits/stdc++.h>
#define int long long

void solve() {
  int x1, x2, y;
  std::cin >> x1 >> x2 >> y;
  int a = std::abs(x1 - x2);
  if (a == 0 || y == 0) {
    std::cout << 0 << '\n';
    return;
  }
  double b = std::abs(1.0 / std::abs(y) * x1 - 1.0 / std::abs(y) * x2);
  double h = a / 2.0 / b;
  double ans = 0.5 * h * (a - b * h);
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
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