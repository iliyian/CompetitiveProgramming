#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int x = 2; x * x <= n * 2 - 1; x++) {
    int y = x * x;
    if ()
    ans += n - (y / 2 + 1) + 1;
    std::cerr << ans << '\n';
  }
  std::cout << ans << '\n';
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