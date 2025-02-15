// date: 2025-01-24 23:57:28
// tag: 基于某些神秘的数论原理的暴力

#include <bits/stdc++.h>
#define int long long

void solve() {
  int l, r, g;
  std::cin >> l >> r >> g;
  l = (l + g - 1) / g, r /= g;
  // std::cerr << std::format("({},{})\n", l, r);
  for (int d = r - l; d >= 0; d--) {
    for (int i = l; i + d <= r; i++) {
      int j = i + d;
      // std::cerr << i << ' ' << j << '\n';
      if (std::gcd(i, j) == 1) {
        std::cout << i * g << ' ' << j * g << '\n';
        return;
      }
    }
  }
  std::cout << -1 << ' ' << -1 << '\n';
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