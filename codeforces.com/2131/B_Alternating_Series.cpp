#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      std::cout << -1 << ' ';
    } else {
      if (i == n) {
        std::cout << 2 << ' ';
      } else {
        std::cout << 3 << ' ';
      }
    }
  }
  std::cout << '\n';
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