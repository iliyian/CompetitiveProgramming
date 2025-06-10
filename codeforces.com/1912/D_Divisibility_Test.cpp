// date: 2025-05-10 23:41:04
// tag: std永远是对称的。超简单数论

#include <bits/stdc++.h>
#define int long long

void solve() {
  int b, n;
  std::cin >> b >> n;
  int t = b;
  for (int i = 1; i <= n * 2; i++) {
    if (t % n == 0) {
      std::cout << 1 << ' ' << i << '\n';
      return;
    }
    t = t * b % n;
  }
  t = b;
  for (int i = 1; i <= n * 2; i++) {
    if (t % n == n - 1) {
      std::cout << 3 << ' ' << i << '\n';
      return;
    }
    t = t * b % n;
  }
  t = b;
  for (int i = 1; i <= n * 2; i++) {
    if (t % n == 1) {
      std::cout << 2 << ' ' << i << '\n';
      return;
    }
    t = t * b % n;
  }
  std::cout << 0 << '\n';
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