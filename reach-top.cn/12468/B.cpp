#include <bits/stdc++.h>
#define int long long

void solve() {
  int x, ans = -1, mx = -1;
  while (std::cin >> x, x) {
    int sum = 0, t = x;
    while (x) sum += x % 10, x /= 10;
    if (sum > mx) {
      mx = sum;
      ans = t;
    }
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