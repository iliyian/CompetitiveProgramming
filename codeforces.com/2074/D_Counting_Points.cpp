#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 2>> a(n + 1);
  int mxr = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][1];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][0];
    mxr = std::max(mxr, a[i][0]);
  }
  std::sort(a.begin() + 1, a.end());
  int ans = 0;
  for (int h = mxr; h >= 0; h--) {
    std::vector<std::pair<int, int>> ranges;
    auto p = std::lower_bound(a.begin() + 1, a.end(), std::array<int, 2>{h, LLONG_MIN}) - a.begin();
    // std::cerr << p << ' ' << h << ' ' << mxr << '\n';
    for (int i = p; i <= n; i++) {
      auto [r, x] = a[i];
      // if (r >= h) {
        int d = std::floor(std::sqrtl(r * r - h * h));
        ranges.push_back({x - d, x + d});
        // std::cerr << x - d << ' ' << d + x << '\n';
      // }
    }
    std::sort(ranges.begin(), ranges.end());
    int pl = LLONG_MIN, pr = LLONG_MIN;
    for (auto [l, r] : ranges) {
      // std::cerr << l << ' ' << r << ' ' << h << '\n';
      if (pl == LLONG_MIN) {
        pl = l, pr = r;
      } else if (l > pr) {
        ans += (pr - pl + 1) * (h == 0 ? 1 : 2);
        pl = l, pr = r;
      } else {
        pr = std::max(pr, r);
      }
    }
    if (pl != LLONG_MIN) {
      ans += (pr - pl + 1) * (h == 0 ? 1 : 2);
    }
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