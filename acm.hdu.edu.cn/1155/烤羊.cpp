#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  int a[3] {};
  std::cin >> n;
  for (int i = 0; i < 3; i++) {
    std::cin >> a[i];
  }
  int ans = n;
  for (int i = 7; i >= 0; i--) {
    int s = 0;
    for (int j = 0; j < 3; j++) {
      if (i >> j & 1) {
        s += a[j];
      }
    }
    // std::cerr << s << ' ';
    if (s <= n) {
      ans = std::min(ans, n - s);
    }
  }
  // std::cerr << '\n';
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