#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  if (a * c * e != b * d * f) {
    std::cout << -1 << '\n';
    return;
  }
  double x = (double)a / b, y = (double)c / d;
  if (x * y + y > 1 && x * y + 1 > y && y + 1 > x * y) {
    std::cout << 1 << '\n';
  } else {
    std::cout << -1 << '\n';
  }
}

signed main() {
  freopen("N.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}