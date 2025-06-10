#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n % 2 == 0) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << n << ' ' << 2 << ' ' << 1 << ' ';
  for (int i = 3; i <= n - 1; i++) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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