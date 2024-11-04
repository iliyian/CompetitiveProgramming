#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n <= 3) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << n + 1 << '\n';
  std::cout << "1 2\n2 3\n3 1\n";
  for (int i = 3; i <= n - 1; i++) {
    std::cout << i << ' ' << i + 1 << '\n';
  }
  std::cout << n << ' ' << 2 << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}