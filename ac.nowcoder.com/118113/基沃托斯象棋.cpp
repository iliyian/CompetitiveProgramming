#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int mxx = 0, mnx = 0, mxy = 0, mny = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    int _x = x + y, _y = x - y;
    mxx = std::max(mxx, _x);
    mxy = std::max(mxy, _y);
    mnx = std::min(mnx, _x);
    mny = std::min(mny, _y);
    std::cout << std::max(mxx - mnx, mxy - mny) << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}