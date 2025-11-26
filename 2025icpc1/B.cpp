#include <bits/stdc++.h>
// #define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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