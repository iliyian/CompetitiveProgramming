#include <bits/stdc++.h>
#define int long long

void solve() {
  int w, h, a, b;
  std::cin >> w >> h >> a >> b;
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  int d1 = std::abs(x1 - x2);
  int d2 = std::abs(y1 - y2);
  // std::cerr << d1 << ' ' << d2 << '\n';
  if ((d1 > 0) && d1 % a == 0 || (d2 > 0) && (d2 % b == 0)) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
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