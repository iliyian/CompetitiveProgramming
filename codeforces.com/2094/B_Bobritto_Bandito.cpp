#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, l, r;
  std::cin >> n >> m >> l >> r;
  while (m != n && r > 0) r--, n--;
  while (m != n && l < 0) l++, n--;
  std::cout << l << ' ' << r << '\n';
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