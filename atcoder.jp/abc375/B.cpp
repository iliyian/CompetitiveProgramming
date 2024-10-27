#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("B.in", "r", stdin);
  int n;
  std::cin >> n;
  double ans = 0;
  int px = 0, py = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    ans += std::sqrt((x - px) * (x - px) + (y - py) * (y - py));
    px = x, py = y;
  }
  ans += std::sqrt(px * px + py * py);
  std::cout << std::fixed << std::setprecision(20) << ans << '\n';
  return 0;
}