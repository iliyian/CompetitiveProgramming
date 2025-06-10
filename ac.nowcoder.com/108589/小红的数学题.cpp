#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n < 3) {
    std::cout << -1 << '\n';
    return;
  }
  if (n % 2 == 1) {
    std::cout << (n - 1) / 2 + 1 << ' ' << (n - 1) / 2 << '\n';
    return;
  }
  if (n < 8) {
    std::cout << -1 << '\n';
    return;
  }
  for (int x = 3; x * x <= n + 1; x++) {
    if ((n + 1) % x == 0 && ((n + 1) / x) % 2 == 1) {
      int a = (x - 1) / 2, b = ((n + 1) / x - 1) / 2;
      std::cout << 2 * (a + b) << ' ' << 4 * a * b << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
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