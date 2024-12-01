#include <bits/stdc++.h>
#define int long long

void solve() {
  int A, B, C, D;
  std::cin >> A >> B >> C >> D;
  int ans = 4;
  if (A < 4) {
    std::cout << 0 << '\n';
    return;
  }
  for (int d = 1; d <= D; d++) {
    for (int aa = 1; aa * aa <= d; aa++) {
      if (d % aa == 0) {
        int bb = d / aa;
        if (aa + bb <= B && aa + bb <= C) {
          ans = std::max(ans, d + 4 + (aa + bb) * 2);
        }
      }
    }
  }
  std::cout << std::max(ans, std::min(B, C) * 2 + 4) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
}