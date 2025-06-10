#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, x;
  std::cin >> n >> m >> x;
  // if (m == 0) {
  //   std::cout << x << '\n';
  //   return;
  // }
  std::cout << (1ll << (n - m + 1)) - (x - 1) << '\n';
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