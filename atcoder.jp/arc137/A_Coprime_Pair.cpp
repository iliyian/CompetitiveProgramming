#include <bits/stdc++.h>
#define int long long

void solve() {
  int l, r;
  std::cin >> l >> r;
  for (int d = r - l; d >= 0; d--) {
    for (int i = l; i + d <= r; i++) {
      int j = i + d;
      // std::cerr << i << ' ' << j << '\n';
      if (std::gcd(i, j) == 1) {
        std::cout << d << '\n';
        return;
      }
    }
  }
  std::cout << -1 << '\n';
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