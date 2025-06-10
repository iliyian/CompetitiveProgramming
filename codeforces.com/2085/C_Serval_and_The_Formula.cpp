#include <bits/stdc++.h>
#define int long long

void solve() {
  int x, y;
  std::cin >> x >> y;
  if (x == y) {
    std::cout << -1 << '\n';
    return;
  }
  if (x < y) std::swap(x, y);
  for (int i = 0; i <= 60; i++) {
    if ((1ll << i) > x) {
      int k = (1ll << i) - x;
      std::cout << k << '\n';
      // std::cerr << (x + k) + (y + k) << ' ' << ((x + k) ^ (y + k)) << '\n';
      return;
    }
  }
  assert(false);
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