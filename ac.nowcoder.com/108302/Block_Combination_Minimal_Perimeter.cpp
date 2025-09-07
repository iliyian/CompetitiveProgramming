#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int s = n * (n + 1) / 2;
  int t = sqrtl(s), ans = LLONG_MAX / 3;
  for (int i = (t + 1); i >= 1; i--) {
    if (s % i == 0) {
      if (std::max(i, s / i) >= n) {
        ans = std::min(ans, (i + (s / i)) * 2);
      }
      // std::cout << (i + (s / i)) * 2 << '\n';
      // return;
    }
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