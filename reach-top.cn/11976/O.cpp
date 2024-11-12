#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i > j) {
        std::cout << "00";
      } else {
        std::cout << i << j;
      }
      std::cout << " \n"[j == n];
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