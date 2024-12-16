#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int cur = 0;
  int t = 1;
  while (std::abs(cur) <= n) {
    cur = cur + (t % 2 ? -1 : 1) * (t * 2 - 1);
    t++;
    // std::cout << cur << '\n';
  }
  std::cout << (t % 2 ? "Kosuke" : "Sakurako") << '\n';
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
