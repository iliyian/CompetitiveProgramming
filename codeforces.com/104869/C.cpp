#include <bits/stdc++.h>
#define int long long

void solve() {
  int x, y;
  std::cin >> x >> y;
  int ans = 0;
  while (x < 3) {
    if (x == 2 || y == 2) {
      ans += 2;
    } else {
      ans += 1;
    }
    x++;
  }
  std::cout << ans << '\n';
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