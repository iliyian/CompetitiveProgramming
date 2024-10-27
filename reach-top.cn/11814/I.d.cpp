#include <bits/stdc++.h>
#define int long long

void solve() {
  int n = 1e3;
  int q = n;
  std::cout << n << ' ' << q << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

signed main() {
  freopen("I.in", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    solve();
  }
  return 0;
}