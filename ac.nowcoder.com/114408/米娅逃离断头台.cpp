#include <bits/stdc++.h>
#define int long long

void solve() {
  int x;
  std::cin >> x;
  std::cout << std::fixed << std::setprecision(2) << std::numbers::pi * 0.5 * x * x / 4 << '\n';
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