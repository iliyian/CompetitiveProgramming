#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  int sum = a + b + c + d;
  std::cout << 15 - sum << '\n';
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