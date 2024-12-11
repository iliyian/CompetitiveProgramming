#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, d, s;
  std::cin >> n >> d >> s;
  n /= s, d /= s;
  int u = std::min(d * 2, n);
  if (u <= 1) {
    std::cout << s << '\n';
    return;
  }
  if (u % 2 == 0) {
    std::cout << u * s << '\n';
    return;
  }
  // std::cout << u << '\n';
  for (int i = 1; i * i <= u; i++) {
    if (u % i == 0 && ((u - i <= d && i - 1 <= d) || (u - (u / i) <= d && u / i - 1 <= d))) {
      std::cout << u * s << '\n';
      return;
    }
  }
  std::cout << (u - 1) * s << '\n';
  // std::cout << std::max((u - 1), 1ll) * s << '\n';
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