#include <bits/stdc++.h>
#define int long long

double solve(int x1, int x2, int x3, int x4) {
  if (x1 > x2)
    std::swap(x1, x2);
  if (x3 > x4)
    std::swap(x3, x4);
  if (x1 == x2 && x3 == x4) {
    return (x3 - x1) * (x3 - x1);
  }
  if (x1 == x2) {
    return (x4 * x4 * x4 - x3 * x3 * x3) / 3.0 - x1 * (x4 * x4 - x3 * x3) +
           x1 * x1 * (x4 - x3);
  }
  if (x3 == x4) {
    return (x2 * x2 * x2 - x1 * x1 * x1) / 3.0 - x3 * (x2 * x2 - x1 * x1) +
           x3 * x3 * (x2 - x1);
  }
  return (x2 * x2 * x2 - x1 * x1 * x1) * (x4 - x3) / 3.0 -
         (x2 * x2 - x1 * x1) * (x4 * x4 - x3 * x3) / 2.0 +
         (x2 - x1) * (x4 * x4 * x4 - x3 * x3 * x3) / 3.0;
}

void solve() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  std::cout << std::fixed << std::setprecision(20) << solve(x1, x2, x3, x4) + solve(y1, y2, y3, y4) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}