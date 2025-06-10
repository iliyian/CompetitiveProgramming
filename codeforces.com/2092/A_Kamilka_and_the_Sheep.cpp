#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int mx = LLONG_MIN, mn = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    mx = std::max(mx, x);
    mn = std::min(mn, x);
  }
  std::cout << mx - mn << '\n';
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