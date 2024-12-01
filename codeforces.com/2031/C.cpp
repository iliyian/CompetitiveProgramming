#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i++) {
      std::cout << (i + 1) / 2 << ' ';
    }
    std::cout << '\n';
    return;
  }
  if (n < 27) {
    std::cout << -1 << '\n';
    return;
  }
  int t = 6;
  for (int i = 1; i <= n; i++) {
    if (i == 1 || i == 10 || i == 26) {
      std::cout << 1 << ' ';
    } else if (i == 23 || i == 27) {
      std::cout << 2 << ' ';
    } else {
      std::cout << t++ / 2 << ' ';
    }
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