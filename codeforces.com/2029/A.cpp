#include <bits/stdc++.h>
#define int long long

void solve() {
  int l, r, k;
  std::cin >> l >> r >> k;
  int mx = r / k;
  std::cout << std::max(0ll, mx - l + 1) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}