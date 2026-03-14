#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, ans = 0;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (i % 2 == 0) {
      ans += x;
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