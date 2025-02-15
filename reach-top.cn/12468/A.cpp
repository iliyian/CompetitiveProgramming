#include <bits/stdc++.h>
#define int long long

void solve() {
  for (int i = 1; i <= 10000; i++) {
    bool f = false, g = 0;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        g = 1;
        break;
      }
    }
    if (!g) {
      int t = i;
      while (t) {
        if (t % 10 == 3) f = 1;
        t /= 10;
      }
    }
    if (f) {
      std::cout << i << ' ';
    }
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