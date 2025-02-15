#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  int x = 0, cnt = 0;
  for (int i = 62; i >= 0; i--) {
    if ((a >> i & 1) != (b >> i & 1)) {
      if (__builtin_popcountll(a & ((1ll << i) - 1)) <= 1) {
        std::cout << a << '\n';
        return;
      } else {
        int j = i;
        while (a >> j & 1 ^ 1) j--;
        // std::cerr << j << '\n';
        std::cout << (x ^ (1ll << (j + 1))) << '\n';
        return;
      }
    } else {
      x ^= (int)(a >> i & 1) << i;
      // std::cerr << x << '\n';
      // cnt++;
    }
  }
  std::cout << a << '\n';
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