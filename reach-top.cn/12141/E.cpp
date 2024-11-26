#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  bool f = false;
  while (n) {
    if (n % 10 % 2) {
      std::cout << n % 10;
      f = true;
    }
    n /= 10;
  }
  if (!f) {
    std::cout << 0 << '\n';
  } else {
    std::cout << '\n';
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