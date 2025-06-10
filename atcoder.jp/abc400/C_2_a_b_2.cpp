#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int a = 1;; a++) {
    int two_a = 1ll << a;
    int t = n / two_a;
    if (t == 0) break;
    int x = sqrtl(t);
    // std::cerr << x << ' ';
    ans += (x + 1) / 2;
    // std::cerr << ans << ' ';
    // for (int b = 1; b * b * two_a <= n; b++) {
    //   if (__builtin_popcountll(b) == 1) continue;
    //   std::cerr << b * b * two_a << ' ';
    // }
    // std::cerr << '\n';
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