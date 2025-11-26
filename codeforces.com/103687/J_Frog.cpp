#include <bits/stdc++.h>
#define int long long

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

using std::numbers::pi;

void print(long double deg, long double r) {
  std::cout << cosl(deg / 180 * pi) * r << ' ' << sinl(deg / 180 * pi) * r << '\n';
}

void solve() {
  long double s, t;
  std::cin >> s >> t;
  std::cout << std::fixed << std::setprecision(10);
  if (std::abs(t - s) > 180) {
    if (t > s) t -= 360;
    else t += 360;
  }
  if (s == t) {
    std::cout << 0 << '\n';
    print(s, 1);
    return;
  }
  long double theta = std::asinl((5 + std::sqrtl(55) / 2.0) / 10);
  long double x = 1 + 2 * cosl(theta);
  long double threshold = (theta + std::acosl(x / 2)) * 2 / pi * 180;
  // std::cerr << deg / pi * 180 << '\n';
  bool flag = false;
  if (std::abs(t - s) > 131) {
    std::cout << 4 << '\n';
    flag = true;
    double k;
    if (s > t) {
      k = s - 45;
    } else {
      k = s + 45;
    }
    print(s, 1);
    print(k, sqrtl(2));
    if (s > t) {
      s = k - 45;
    } else {
      s = k + 45;
    }
  }
  // std::cerr << s << ' ' << t << '\n';
  if (std::abs(t - s) <= 90) {
    if (!flag) {
      std::cout << 2 << '\n';
    }
    long double alpha = std::abs(t - s) / 2 / 180 * pi;
    long double deg = (s + t) / 2;
    long double l = cosl(alpha) * 2;
    // std::cerr << l << ' ' << deg << '\n';
    print(s, 1);
    print(deg, l);
    print(t, 1);
    return;
  }
  long double deg = (s + t) / 2;
  long double alpha = std::abs(t - s) / 2.0 / 180 * pi;
  long double dist = sqrtl(1 - (sinl(alpha) - 0.5) * (sinl(alpha) - 0.5)) + cosl(alpha);
  long double dist2 = sqrtl(0.25 + dist * dist);
  long double beta = asinl(0.5 / dist2) / pi * 180;
  std::cout << 3 << '\n';
  print(s, 1);
  if (s > t) {
    print(deg + beta, dist2);
    print(deg - beta, dist2);
  } else {
    print(deg - beta, dist2);
    print(deg + beta, dist2);
  }
  print(t, 1);
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