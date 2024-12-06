#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  if ((n + 1) * k % 2 || k == 1) {
    std::cout << "NO\n";
    return;
  }
  if (k % 2 == 0) {
    std::cout << "YES\n";
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= n; j++) {
        int x = (i % 2 ? j : n - j + 1);
        x = x + (i - 1) / 2 * (i % 2 ? 1 : -1) + n;
        if (x > n) x -= n;
        std::cout << x << ' ';
      }
      std::cout << '\n';
    }
    return;
  }
  std::cout << "YES\n";
  bool f = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 1) {
        std::cout << j << ' ';
      } else if (i == k) {
        int x = ((n - (j - 1) * 2) % n + n) % n;
        if (x == 0) x += n;
        std::cout << x << ' ';
      } else if (i == (k + 1) / 2) {
        int x = (n + 1) / 2 + j - 1;
        if (x > n) x -= n;
        std::cout << x << ' ';
      } else {
        if (f) {
          std::cout << j << ' ';
        } else {
          std::cout << n - j + 1 << ' ';
        }
      }
    }
    if (i != 1 && i != k && i != (k + 1) / 2) f ^= 1;
    std::cout << '\n';
  }
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