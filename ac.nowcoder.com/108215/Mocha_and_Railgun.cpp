#include <bits/stdc++.h>
#define int long long

const long double pi = acos(-1);
constexpr long double eps = 1e-8;

double dis;
int R, d, x, y;

double check(double mid) {
  double xx = dis * cos(mid);
  // , yy = dis * sinl(mid);
  double lx = xx - d, rx = xx + d;
  double lrd = acos(lx / R), rrd = acos(rx / R);
  return std::abs((rrd - lrd) * R);
}

void solve() {
  std::cin >> R >> x >> y >> d;
  // double a = acos(1.0 * d / R);
  // a = pi - a * 2;
  // std::cerr << std::fixed << std::setprecision(20) << a * R << '\n';
  
  dis = sqrt(x * x + y * y);
  double l = 0, r = pi;
  // while (l < r - eps) {
  //   double lmid = (l + r) / 2;
  //   double rmid = lmid + eps;
  //   double lans = check(lmid), rans = check(rmid);
  //   if (lans > rans) r = lmid;
  //   else l = rmid;
  // }
  l = pi;
  // std::cerr << l * 180 / pi << '\n';
  std::cout << std::fixed << std::setprecision(20) << check(l) << '\n';
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