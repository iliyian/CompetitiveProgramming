#include <bits/stdc++.h>
#define int long long

constexpr double eps = 1e-9;

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

const double pi = acos(-1);

void solve() {
  double s, t;
  std::cin >> s >> t;
  double sx = std::cos(s / 180.0 * pi), sy = std::sin(s / 180.0 * pi);
  double tx = std::cos(t / 180.0 * pi), ty = std::sin(t / 180.0 * pi);
  std::cout << std::fixed << std::setprecision(10);
  if (std::abs(t - s) > 180) {
    if (t > s) t -= 360;
    else t += 360;
  }
  if (s == t) {
    std::cout << 0 << '\n';
    std::cout << sx << ' ' << sy << '\n';
    return;
  }
  if (std::abs(t - s) <= 90) {
    double deg = (s + t) / 2.0;
    std::cerr << deg << '\n';
    double l = 1, r = 2;
    while (l <= r - eps) {
      double lmid = (l * 2 + r) / 3, rmid = (l + r * 2) / 3;
      double lx = std::cos(deg / 180 * pi) * lmid, ly = std::sin(deg / 180 * pi) * lmid;
      double rx = std::cos(deg / 180 * pi) * rmid, ry = std::sin(deg / 180 * pi) * rmid;
      // std::cerr <<
      if (std::abs(dis(lx, ly, sx, sy) - 1) <= std::abs(dis(rx, ry, sx, sy) - 1)) {
        r = rmid;
      } else {
        l = lmid;
      }
    }
    std::cout << 2 << '\n';
    std::cout << sx << ' ' << sy << '\n';
    std::cout << std::cos(deg / 180 * pi) * l << ' ' << std::sin(deg / 180 * pi) * l <<'\n';
    std::cout << tx << ' ' << ty << '\n';
    return;
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