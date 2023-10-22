#include <bits/stdc++.h>
using namespace std;

int px, py, ax, ay, bx, by;

double dist(double x0, double y0, double x1, double y1) {
  return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

bool check(double mid) {
  bool a0 = dist(0, 0, ax, ay) < mid, b0 = dist(0, 0, bx, by) < mid,
    ab = dist(ax, ay, bx, by) < 2 * mid,
    ap = dist(ax, ay, px, py) < mid, bp = dist(bx, by, px, py) < mid;
  if (a0 && ap || b0 && bp || a0 && ab && bp || b0 && ab && ap)
    return true;
  return false;
}

void solve() {
  cin >> px >> py >> ax >> ay >> bx >> by;
  double l = 0, r = 3000, ans = -1;
  while (l + 0.0000005 <= r) {
    double mid = l + (r - l) / 2;
    if (check(mid)) r = mid, ans = mid;
    else l = mid;
  }
  cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}