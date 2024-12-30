#include <bits/stdc++.h>
using namespace std;
// #define double long double
const int N = 2e5 + 100;
struct node {
  double x, y;
};
node s;
int n;
node a[N];
double r[N];
int xx, yy, rr;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> xx >> yy;
  s.x = xx;
  s.y = yy;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> xx >> yy >> rr;
    a[i].x = xx;
    a[i].y = yy;
    r[i] = rr;
  }
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    int nxt = i % n + 1;
    if (a[i].x == a[nxt].x) {
      double aa = 1;
      double b = -2 * s.y;
      double c = s.y * s.y + (a[i].x - s.x) * (a[i].x - s.x) - r[i] * r[i];
      double delta = b * b - 4 * aa * c;
      if (delta <= 0)
        continue;
      double xx1 = a[i].x;
      double xx2 = a[i].x;
      double yy1 = (-b + sqrt(delta)) / (2 * aa);
      double yy2 = (-b - sqrt(delta)) / (2 * aa);
      if (yy1 > yy2)
        swap(yy1, yy2);
      yy1 = max(yy1, min(a[i].y, a[nxt].y));
      yy2 = min(yy2, max(a[i].y, a[nxt].y));
      if (yy1 < yy2) {
        double len =
            sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2));
        ans += len;
      }
      continue;
    }
    double k = (a[nxt].y - a[i].y) / (a[nxt].x - a[i].x);
    double bb = (a[nxt].x * a[i].y - a[nxt].y * a[i].x) / (a[nxt].x - a[i].x);
    double aa = 1 + k * k;
    double b = 2 * k * (bb - s.y) - 2 * s.x;
    double c = s.x * s.x + (bb - s.y) * (bb - s.y) - r[i] * r[i];
    double delta = b * b - 4 * aa * c;
    if (delta <= 0)
      continue;
    double xx1 = (-b + sqrt(delta)) / (2 * aa);
    double xx2 = (-b - sqrt(delta)) / (2 * aa);
    if (xx1 > xx2)
      swap(xx1, xx2);
    xx1 = max(xx1, min(a[i].x, a[nxt].x));
    xx2 = min(xx2, max(a[i].x, a[nxt].x));
    if (xx1 < xx2) {
      double yy1 = k * xx1 + bb;
      double yy2 = k * xx2 + bb;
      double len = sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2));
      ans += len;
    }
  }
  cout << fixed << setprecision(10) << ans << '\n';
  return 0;
}