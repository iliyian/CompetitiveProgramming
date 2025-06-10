#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << a + b + c << '\n';
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