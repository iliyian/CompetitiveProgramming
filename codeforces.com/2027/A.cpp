#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int mx1 = 0, mx2 = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    mx1 = std::max(mx1, x);
    mx2 = std::max(mx2, y);
  }
  std::cout << (mx1 + mx2) * 2 << '\n';
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