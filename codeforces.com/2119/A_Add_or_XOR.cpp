#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, x, y;
  std::cin >> a >> b >> x >> y;
  if (a > b) {
    if (a == b + 1 && a % 2 == 1) {
      std::cout << y << '\n';
    } else {
      std::cout << -1 << '\n';
    }
  } else {
    int ans = 0;
    if (a % 2 != b % 2) {
      if (a % 2 == 0) {
        ans += std::min(x, y);
      } else {
        ans += x;
      }
      a++;
    }
    ans += std::min(x, y) * (b - a) / 2 + x * (b - a) / 2;
    std::cout << ans << '\n';
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