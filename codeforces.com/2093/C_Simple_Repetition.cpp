#include <bits/stdc++.h>
#define int long long

void solve() {
  int x, k;
  std::cin >> x >> k;
  if (x == 1) {
    if (k == 1) {
      std::cout << "NO\n";
      return;
    }
    for (int i = 0; i < k - 1; i++) {
      x = x * 10 + 1;
    }
    k = 1;
  }
  if (k > 1) {
    std::cout << "NO\n";
    return;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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