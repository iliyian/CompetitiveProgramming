// date: 2025-07-15 11:23:25
// tag: 主打一个找规律。这tmd怎么可能是有理数取模呢？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  int d = a, c = 180 * b;
  int g = std::gcd(c, d);
  c /= g, d /= g;
  // std::cout << c << ' ' << d << '\n';
  std::cout << c - 1 << '\n';
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