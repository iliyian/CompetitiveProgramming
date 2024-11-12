#include <bits/stdc++.h>
#define int long long

void solve() {
  int la, lb, ra, rb;
  std::cin >> la >> lb >> ra >> rb;
  int mn = la + ra;
  int mx = 0;
  int t = mn;
  while (t) mx = std::max(mx, t % 10), t /= 10;
  for (int i = ra; i <= std::min(rb, ra + 12); i++) {
    for (int j = la; j <= std::min(lb, la + 12); j++) {
      int t = i + j;
      while (t) mx = std::max(mx, t % 10), t /= 10;
    }
  }
  std::cout << mx << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}