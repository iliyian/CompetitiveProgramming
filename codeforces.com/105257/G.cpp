#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x;
  std::cin >> n >> x;
  int ans = 1;
  auto check = [&](int c) {
    while (c) {
      if (c % 10 == x) return true;
      c /= 10;
    }
    return false;
  };
  for (int i = 1; i <= n; i++) {
    if (!check(i)) ans++;
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