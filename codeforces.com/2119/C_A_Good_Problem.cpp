#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, l, r, k;
  std::cin >> n >> l >> r >> k;
  if (n % 2 == 1) {
    std::cout << l << '\n';
    return;
  }
  if (n == 2 || __builtin_clzll(l) == __builtin_clzll(r)) {
    std::cout << -1 << '\n';
    return;
  }
  if (k <= n - 2) {
    std::cout << l << '\n';
    return;
  }
  std::cout << (1ll << (64 - __builtin_clzll(l))) << '\n';
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