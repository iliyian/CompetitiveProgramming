// date: 2025-02-13 13:22:30
// tag: 什么纯粹暴力

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int t = 10;
  auto check = [&](int x) {
    while (x) {
      if (x % 10 == 7) return true;
      x /= 10;
    }
    return false;
  };
  if (check(n)) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = 7;
  for (int i = 1; i <= 10; i++) {
    int cur = n;
    for (int j = 1; j <= 7; j++) {
      cur += t - 1;
      if (check(cur)) {
        ans = std::min(ans, j);
      }
    }
    t *= 10;
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