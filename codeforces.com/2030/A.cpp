#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  auto [mn, mx] = std::minmax_element(a.begin() + 1, a.end());
  std::cout << (*mx - *mn) * (n - 1) << '\n';
  return;
  // std::swap(*x, a[1]);
  // int mn = a[1], mx = a[1], ans = 0;
  // for (int i = 1; i <= n; i++) {
  //   mx = std::max(mx, a[i]);
  //   mn = std::min(mn, a[i]);
  //   ans += mx - mn;
  // }
  // std::cout << ans << '\n';
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