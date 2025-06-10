#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x;
  std::cin >> n >> x;
  if (n == 1 && x == 0) {
    std::cout << -1 << '\n';
    return;
  }
  if (x == 0) {
    if (n % 2 == 0) {
      std::cout << n << '\n';
    } else {
      std::cout << n + 3 << '\n';
    }
    return;
  }
  if (x == 1) {
    if (n % 2 == 0) {
      std::cout << n + 3 << '\n';
    } else {
      std::cout << n << '\n';
    }
    return;
  }
  int p = __builtin_popcountll(x);
  if (p >= n) {
    std::cout << x << '\n';
    return;
  }
  int r = n - p;
  std::cout << x + r + (r % 2) << '\n';
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