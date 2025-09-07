#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n % 6 == 4) {
    std::cout << 2 << '\n';
  } else {
    std::cout << 0 << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int n = 1; n <= 20; n++) {
  //   for (int i = 0; i < (1 << n); i++) {
  //     int x = 123, y = 321;
  //     for (int j = 0; j < n - 1; j++) {
  //       int a = i >> j & 1, b = i >> (j + 1) & 1;
  //       if (a == 1 && b == 1) {
  //         x = 0;
  //       } else  if (a == 0 && b == 0) {
  //         y = 0;
  //       } else if (a == 1 && b == 0) {
  //         x = x ^ y;
  //       } else {
  //         y = y ^ x;
  //       }
  //     }
  //     if (y == 123 && x == 321) {
  //       for (int j = 0; j < n; j++) {
  //         std::cout << (i >> j & 1);
  //       }
  //       std::cout << '\n';
  //     }
  //   }
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}