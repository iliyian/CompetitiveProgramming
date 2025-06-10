#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  std::cout << 3 << '\n';
  if (a > b) {
    std::cout << b << ' ' << b << ' ' << 3 * a - 2 * b << '\n';
  } else {
    std::cout << 3 * a - 2 * b << ' ' << b << ' ' << b << '\n';
  }
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