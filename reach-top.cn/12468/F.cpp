#include <bits/stdc++.h>
#include <cctype>
#define int long long

void solve() {
  double x;
  std::cin >> x;
  if (x <= 3) {
    std::cout << 200;
  } else if (x <= 5) {
    std::cout << 200 + (x - 3) * 20;
  } else {
    std::cout << 200 + 2 * 20 + (x - 5) * 30;
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}