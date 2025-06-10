#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans = (1ll << (63 - __builtin_clzll(n)));
  if (ans == n) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << ans << '\n';
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