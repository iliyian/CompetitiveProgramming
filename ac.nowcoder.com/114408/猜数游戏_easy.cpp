#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int x = 63 - __builtin_clzll(n);
  if ((1 << x) == n) {
    std::cout << x << '\n';
  } else {
    std::cout << x + 1 << '\n';
  }
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