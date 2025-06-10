#include <bits/stdc++.h>
#define int long long

const double pi = acos(-1);

bool eq(double x, double y) {
  return std::abs(x - y) <= 1e-4;
}

void solve() {
  double r, v1, v2;
  std::cin >> r >> v1 >> v2;
  int n;
  std::cin >> n;
  std::vector<double> a(n + 1), t(n + 1);
  double ans = 0;
  std::cerr << v1 << '\n';
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    double rr = sqrt(x * x + y * y);
    a[i] = acos(1.0 * x / rr);
    if (y > 0) a[i] = 2 * pi - a[i];
    std::cerr << a[i] << ' ';
    double t = rr / v2;
    double tt = a[i] / v1; // +2kpi==t
    std::cerr << t << ' ' << tt << ' ' << (tt - t) / (2 * pi / v1) << '\n';
  }
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