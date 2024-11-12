#include <bits/stdc++.h>
#define int long long

void solve() {
  int a[3][5];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      std::cin >> a[i][j];
      if (a[i][j]) {
        std::cout << std::setw(3) << i + 1;
        std::cout << std::setw(3) << j + 1;
        std::cout << std::setw(3) << a[i][j] << '\n';
      }
    }
  }
}

signed main() {
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}