#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
//   if (n % 2) {
// 
//   } else {
//     if (n / 2 % 2) {
//       std::cout << 0 << ' ' << n 
//     } else {
// 
//     }
//   }
  if (n % 3 == 0) {
    std::cout << 1 << ' ' << n / 3 << '\n';
  } else {
    std::cout << 0 << ' ' << n / 3 + n % 3 << '\n';
  }
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