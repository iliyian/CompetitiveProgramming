#include <bits/stdc++.h>
#include <numbers>

int x11, y11, x12, y12, x21, y21, x22, y22;
double x1, y1_, x2, y2, r2, x3, y3;

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
};

void solve() {
  std::cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;

  x1 = (x11 + x12) / 2.0, y1_ = (y11 + y12) / 2.0;
  x2 = (x21 + x22) / 2.0, y2 = (y21 + y22) / 2.0;

  r2 = dis(x21, y21, x22, y22) / 2;

  double t = r2 / std::numbers::sqrt2;
  double x = (x1 < x2 ? x2 - t : x2 + t), y = (y1_ < y2 ? y2 - t : y2 + t);
  double ans = std::abs(x - x1) + std::abs(y - y1_);
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
}

signed main() {
  freopen("J.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}