#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    if (n % 2 == 0 && (i == n / 2 || i == n / 2 + 1) || n % 2 == 1 && i == (n + 1) / 2) {
      std::cout << "=";
    } else {
      std::cout << "-";
    }
  }
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