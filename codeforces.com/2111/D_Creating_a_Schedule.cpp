// date: 2025-06-05 22:48:12
// tag: 什么水题？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    if (i % 2) {
      for (int j = 1; j <= 3; j++) {
        std::cout << a[(i + 1) / 2] << ' ' << a[m - (i + 1) / 2 + 1] << ' ';
      }
    } else {
      for (int j = 1; j <= 3; j++) {
        std::cout << a[m - (i + 1) / 2 + 1] << ' ' << a[(i + 1) / 2] << ' ';
      }
    }
    std::cout << '\n';
  }
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