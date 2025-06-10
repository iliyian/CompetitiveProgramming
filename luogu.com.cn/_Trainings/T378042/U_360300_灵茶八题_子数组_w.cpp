#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    ans += i * (n - i + 1) * x;
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