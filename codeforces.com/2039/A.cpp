#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cout << (i - 1) * 2 + 1 << ' ';
  }
  std::cout << '\n';
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