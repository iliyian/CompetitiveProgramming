#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  if (b == a) {
    std::cout << 0 << '\n';
    return;
  }
  if (b > a && (b - a) % 2 == 1 || b < a && (a - b) % 2 == 0) {
    std::cout << 1 << '\n';
    return;
  }
  if (b < a && (a - b) % 2 == 1) {
    std::cout << 2 << '\n';
    return;
  }
  if (b > a && (b - a) % 2 == 0) {
    int t = b - a;
    int ans = t & -t;
    for (int i = 1; i <= 40; i++) {
      int t = b - (a - (1ll << i));
      ans = std::min(ans, (t & -t) + 1);
    }
    std::cout << ans << '\n';
    return;
  }
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