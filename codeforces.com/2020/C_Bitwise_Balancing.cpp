// date: 2025-01-31 21:52:41
// tag: 位运算性质,a|b>=a&c

#include <bits/stdc++.h>
#define int long long

void solve() {
  int b, c, d;
  std::cin >> b >> c >> d;
  int a = c ^ d;
  if ((a | b) - (a & c) == d) {
    std::cout << a << '\n';
  } else {
    std::cout << -1 << '\n';
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