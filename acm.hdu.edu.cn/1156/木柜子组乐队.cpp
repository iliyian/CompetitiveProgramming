#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, c, d, e;
  std::cin >> a >> b >> c >> d >> e;
  int ans = a * b * c * d * e + a * b * c * d * (d - 1) / 2;
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