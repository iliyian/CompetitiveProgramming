#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < (1 << n); i++) {
    std::cout << __builtin_popcountll(i) % 2;
  }
  std::cout << '\n';
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