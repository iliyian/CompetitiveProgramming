// date: 2025-05-04 21:23:40
// tag: 按位贪心，但是常用的把小于等于转换成小于的技巧。然后也是少见的两个log

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  x++;
  int ans = -1;
  for (int i = 31; i >= 0; i--) {
    if (x >> i & 1) {
      int c[32] {}, cur = 0;
      bool f = true;
      for (int k = 1; k <= n; k++) {
        f = true;
        for (int j = i; j <= 31; j++) {
          if ((j == i) || x >> j & 1 ^ 1) {
            c[j] += a[k] >> j & 1;
            if (c[j] % 2) {
              f = false;
            }
          }
        }
        if (f) {
          cur++;
        }
      }
      if (f) {
        ans = std::max(ans, cur);
      }
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