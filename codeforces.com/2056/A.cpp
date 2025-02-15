#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  int x1, y1;
  std::cin >> x1 >> y1;
  int xx = x1, yy = y1;
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    std::cin >> x >> y;
    xx += x, yy += y;
  }
  xx += m, yy += m;
  std::cout << (xx - x1) * 2 + (yy - y1) * 2 << '\n';
  // std::cout << xx << ' ' << yy << '\n';
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