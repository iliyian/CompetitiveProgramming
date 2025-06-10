#include <bits/stdc++.h>
#define int long long

void solve() {
  double a, b, n;
  std::cin >> a >> b >> n;
  double ans = 0;
  int mx = 2e6;
  for (int t = 1; t <= mx; t++) {
    double x = a * t / mx;
    double y = b * pow(1.0 - pow(x / a, n), 1.0 / n);
    // std::cerr << x << ' ' << y << '\n';
    ans += y * a / mx;
  }
  ans *= 4;
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
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