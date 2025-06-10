#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n < 3) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << 1 << ' ' << n << ' ';
  for (int i = n - 1; i >= 2; i--) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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