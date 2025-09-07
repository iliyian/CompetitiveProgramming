#include <bits/stdc++.h>
#define int long long

void solve() {
  int k, a, b, x, y;
  std::cin >> k >> a >> b >> x >> y;
  if (a < b) std::swap(a, b), std::swap(x, y);
  int ans = std::max(0ll, (k - a + 1 + std::min(x, y) - 1) / std::min(x, y));
  k -= ans * std::min(x, y);
  ans += std::max(0ll, (k - b + 1 + y - 1) / y);
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