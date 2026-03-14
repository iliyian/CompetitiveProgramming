#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, y;
  std::cin >> x >> n >> y;
  std::cout << x * n + y << '\n';
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