#include <bits/stdc++.h>
#define int long long

void solve() {
  int m, a, b, c;
  std::cin >> m >> a >> b >> c;
  a = std::min(m, a);
  b = std::min(m, b);
  c = std::min(c, m * 2 - a - b);
  std::cout << a + b + c << '\n';
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