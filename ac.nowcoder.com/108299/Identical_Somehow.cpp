#include <bits/stdc++.h>
#define int long long

void solve() {
  int x, y;
  std::cin >> x >> y;
  if (x == 1 && y == 1) {
    std::cout << 1 << '\n';
    return;
  }
  if (x == 1 || y == 1) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << 1 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int x = 1; x <= 10; x++) {
    for (int y = 1; y <= 10; y++) {
      for (int k = 1; k <= 10000; k++) {
        if (k % x + x % k == k % y + y % k) {
          std::cout << x << ' ' << y << ' ' << k << '\n';
          break;
        }
      }
    }
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}