#include <bits/stdc++.h>
#define int double

void solve() {
  int _sx, _sy;
  signed n;
  std::cin >> _sx >> _sy >> n;
  std::vector<int> x(n + 1), y(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i] >> r[i];
  }
  auto pow2 = [&](double x) { return x * x; };
  auto dis = [&](double x1, double y1, double x2, double y2) {
    return sqrtl(pow2(x2 - x1) + pow2(y2 - y1));
  };
  auto calc = [&](int x1, int y1, int x2, int y2, double r) -> double {
    if (x1 > x2) std::swap(x1, x2), std::swap(y1, y2);
    bool f = false;
    int sx = _sx, sy = _sy;
    if (x1 == x2) {
      std::swap(x1, y1), std::swap(x2, y2);
      sx = _sy, sy = _sx;
    }
    double k = double(y2 - y1) / (x2 - x1);
    double b = y1 - k * x1;
    // (k2+1)x2+(2kb-2ksy-2sx)x+sy2+b2-2bsy+sx2-r2=0
    double _a = (pow2(k) + 1);
    double _b = (2 * k * b - 2 * k * sy - 2 * sx);
    double _c = (pow2(sy) + pow2(b) - 2 * b * sy + pow2(sx) - pow2(r));
    double delta = _b * _b - 4 * _a * _c;
    if (delta < 0) return 0;
    auto _x1 = (-_b - sqrt(delta)) / (_a * 2);
    auto _x2 = (-_b + sqrt(delta)) / (_a * 2);
    auto _y1 = k * _x1 + b;
    auto _y2 = k * _x2 + b;
    // std::cout << _a << ' ' << _b << ' ' << _c << '\n';
    // std::cout << _x1 << ' ' << _y1 << ' ' << _x2 << ' ' << _y2 << '\n';
    // std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    double ans = 0;
    if (_x1 < x1 && x1 < _x2 && _x2 < x2) {
      return dis(x1, y1, _x2, _y2);
    } else if (x1 < _x1 && _x1 < x2 && x2 < _x2) {
      return dis(_x1, _y1, x2, y2);
    } else if (x1 < _x1 && _x2 < x2) {
      return dis(_x1, _y1, _x2, _y2);
    } else if (_x1 < x1 && x2 < _x2) {
      return dis(x1, y1, x2, y2);
    } else {
      return 0;
    }
  };
  double ans = 0;
  for (signed i = 1; i <= n; i++) {
    double cur = calc(x[i], y[i], x[i % n + 1], y[i % n + 1], r[i]);
    // std::cout << cur << '\n';
    ans += cur;
  };
  std::cout << std::fixed << std::setprecision(10) << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}