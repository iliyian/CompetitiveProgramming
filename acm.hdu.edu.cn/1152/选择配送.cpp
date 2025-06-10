#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> a(n + 1), b(m + 1);
  int mxx = LLONG_MIN, mnx = LLONG_MAX;
  int mxy = LLONG_MIN, mny = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    int xx = x + y, yy = x - y;
    a[i] = {xx, yy};
    mxx = std::max(mxx, xx);
    mnx = std::min(mnx, xx);
    mxy = std::max(mxy, yy);
    mny = std::min(mny, yy);
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    int xx = x + y, yy = x - y;
    b[i] = {xx, yy};
  }
  // std::sort(a.begin() + 1, a.end());
  // std::sort(b.begin() + 1, b.end());
  int ans = LLONG_MAX;
  for (int i = 1; i <= m; i++) {
    auto [x, y] = b[i];
    ans = std::min(ans, std::max({std::abs(x - mxx), std::abs(x - mnx), std::abs(y - mxy), std::abs(y - mny)}));
  }
  std::cout << ans << '\n';
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