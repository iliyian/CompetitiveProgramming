// date: 2024-03-20 17:54:00
// tag: 计算几何，高中数学
// wa#01: 输入写成int了
// wa#02: epsilon过小

#include <bits/stdc++.h>
#define int long long
using namespace std;

bool eq(double x, double y) {
  return abs(x - y) < 1e-4;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  double xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  auto dis = [](double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  };
  double a = dis(xb, yb, xc, yc);
  double b = dis(xa, ya, xc, yc);
  double c = dis(xa, ya, xb, yb);
  double cosBAC = (b * b + c * c - a * a) / (b * c * 2);
  double sinBAC = sqrt(1 - cosBAC * cosBAC);
  double R = a / sinBAC / 2;
  double cosA = (R * R * 2 - a * a) / (R * R * 2);
  double cosB = (R * R * 2 - b * b) / (R * R * 2);
  double cosC = (R * R * 2 - c * c) / (R * R * 2);
  double A = acos(cosA), B = acos(cosB), C = acos(cosC);

  double pi = acos(-1);
  for (int i = 3; i <= 100; i++) {
    double t = 2 * pi / i;
    double aa = A / t, bb = B / t, cc = C / t;
    if (eq(aa, round(aa)) && eq(bb, round(bb)) ||
        eq(aa, round(aa)) && eq(cc, round(cc)) ||
        eq(bb, round(bb)) && eq(cc, round(cc))) {
      double S = i * (R * R * sin(t) / 2);
      cout << fixed << setprecision(10) << S << '\n';
      return 0;
    }
  }

  return 0;
}