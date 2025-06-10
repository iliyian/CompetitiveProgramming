#include <bits/stdc++.h>
#define int long long

void solve() {
  int ans = 0;
  for (int i = 1; i <= 100; i++) {
    ans ^= i;
    std::cout << ans << '\n';
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