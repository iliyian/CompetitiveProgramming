#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  std::cout << (a * b / std::gcd(a, b)) << '\n';
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