#include <bits/stdc++.h>
#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < n - i + 1; i++) {
    int x = a[i], y = a[n - i + 1];
    if (std::bit_width((u64)x) != std::bit_width((u64)y)) {
      std::cout << -1 << '\n';
      return;
    }
    while (x != y) {
      // std::cerr << x << ' ' << y << '\n';
      if (x > y) std::swap(x, y);
      if (x == 0 && y == 1) {
        std::cout << -1 << '\n';
        return;
      }
      x ^= x >> 1;
      ans++;
    }
  }
  std::cout << ans << '\n';
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