#include <bits/stdc++.h>
#define int long long

void solve() {
  int a[5] {}, b[5] {};
  int asum = 0, bsum = 0;
  for (int i = 0; i < 5; i++) {
    std::cin >> a[i];
    asum += a[i];
  }
  for (int i = 0; i < 5; i++) {
    std::cin >> b[i];
    bsum += b[i];
  }
  std::cout << (asum < bsum ? "Red" : "Blue") << '\n';
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