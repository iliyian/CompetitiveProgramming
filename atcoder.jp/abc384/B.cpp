#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, r;
  std::cin >> n >> r;
  for (int i = 1; i <= n; i++) {
    int d, a;
    std::cin >> d >> a;
    if (d == 1 && (r < 1600 || r > 2799) || d == 2 && (r < 1200 || r > 2399)) {

    } else {
      r += a;
    }
  }
  std::cout << r << '\n';
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
