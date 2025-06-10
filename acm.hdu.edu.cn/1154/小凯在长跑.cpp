#include <bits/stdc++.h>
#define int long long

constexpr double eps = 1e-9;

void solve() {
  int d, r, x, y;
  std::cin >> d >> r >> x >> y;
  x = std::abs(x), y = std::abs(y);
  double k = 1.0 * (y - d) / x;
  auto dis = [&](double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  };
  if (y >= d) {
    double dist = std::abs(r - dis(0, d, x, y));
    // int ans = std::min(std::round(dist), std::abs());
    // std::cerr << dist << '\n';
    int ans = std::round(dist);
    std::cout << ans << '\n';
  } else {
    std::cout << std::abs(x - r) << '\n';
  }
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