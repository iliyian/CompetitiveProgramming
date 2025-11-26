#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

void solve() {
  // int n = (int)1e1, q = (int)1e4, w = (int)100;
  // int n = rd() % (int)1e4 + 1, q = rd() % (int)1e4 + 1, w = rd() % (int)1 + 1;
  int n = (int)1e5, q = 1;
  std::cout << n << ' ' << q << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << 1 << ' ';
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << rd() % w + 1 << ' ';
  // }
  std::cout << '\n';
  std::cout << 1 << ' ' << 1 << '\n';
  // for (int i = 1; i <= q; i++) {
  //   int x = rd() % w + 1, y = rd() % w + 1;
  //   std::cout << x << ' ' << y << '\n';
  // }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}