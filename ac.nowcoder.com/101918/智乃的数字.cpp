#include <bits/stdc++.h>
#define int long long

int a[] = {3, 5, 9, 15, 21, 25, 27};

void solve() {
  int n;
  std::cin >> n;
  std::cout << ((n - 1) / 7) * 30 + a[(n - 1) % 7] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int i = 1; i <= 1000; i++) {
  //   if ((i % 3 == 0 || i % 5 == 0) && i % 2 == 1) {
  //     std::cerr << i << ' ';
  //   }
  // }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
