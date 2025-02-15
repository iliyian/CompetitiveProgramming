#include <bits/stdc++.h>
#define int long long

void solve() {
  int a;
  double t;
  std::cin >> a >> t;
  std::cout << std::fixed << std::setprecision(20) << a * std::cos(t) << ' ' << a * -std::sin(t) << '\n';
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