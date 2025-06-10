// date: 2025-03-07 16:40:22
// tag: 子数组的和的异或和，拆位算贡献，分别计数，两个log

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::sort(b.begin() + 1, b.end());
  int ans = 0;
  for (int j = 30; j >= 0; j--) {
    std::sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
      auto l = std::lower_bound(a.begin() + 1, a.end(), (1ll << j) - b[i]) - a.begin();
      auto r = std::upper_bound(a.begin() + 1, a.end(), (1ll << (j + 1)) - 1 - b[i]) - a.begin() - 1;
      if (r >= l && l != n + 1 && r != 0) {
        ans ^= ((r - l + 1) % 2) << j;
        // std::cerr << 1ll << ' ' << j << ' ' << i << ' ' << l << ' ' << r << '\n';
      }
      l = std::lower_bound(a.begin() + 1, a.end(), (1ll << j) + (1ll << (j + 1)) - b[i]) - a.begin();
      r = std::upper_bound(a.begin() + 1, a.end(), (1ll << (j + 2)) - 1 - b[i]) - a.begin() - 1;
      if (r >= l && l != n + 1 && r != 0) {
        ans ^= ((r - l + 1) % 2) << j;
        // std::cerr << 2 << ' ' << j << ' ' << i << ' ' << l << ' ' << r << '\n';
      }
      // std::cerr << j << ' ' << i << ' ' << l << ' ' << r << '\n';
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] >> j & 1) {
        a[i] ^= 1ll << j;
      }
      if (b[i] >> j & 1) {
        b[i] ^= 1ll << j;
      }
    }
  }
  std::cout << ans << '\n';
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