#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n % 15 <= 2) {
    std::cout << n / 15 * 3 + n % 15 + 1 << '\n';
    return;
  }
  std::cout << n / 15 * 3 + 3 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int i = 1; i <= 1e4; i++) {
  //   if (i % 3 == i % 5) {
  //     std::cerr << i << ' ';
  //   }
  // }
  // return 0;

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}