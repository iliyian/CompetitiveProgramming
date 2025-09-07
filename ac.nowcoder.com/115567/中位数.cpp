#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int mn = LLONG_MAX , mx = LLONG_MIN;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    mn = std::min(mn, x), mx = std::max(mx, x);
  }
  std::cout << (mn + mx) / 2 << '\n';
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