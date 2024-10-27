#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  bool prv = false;
  for (int i = 1; i <= n + 1; i++) {
    int x;
    std::cin >> x;
    if (x == 0) {
      continue;
    }
    if (x < 0) {
      std::cout << '-';
    }
    if (x > 0 && prv) {
      std::cout << '+';
    }
    prv = true;
    if (std::abs(x) != 1 || i == n + 1) {
      std::cout << std::abs(x);
    }
    if (i == n + 1) break;
    std::cout << "x";
    if (i != n) {
      std::cout << "^" << n - i + 1;
    }
  }
  return 0;
}