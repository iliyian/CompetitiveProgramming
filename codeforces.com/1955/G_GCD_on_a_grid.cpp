// date: 2025-04-08 00:00:06
// tag: 弱智结论题

#include <bits/stdc++.h>
#define int long long

int a[101][101], f[101][101];

void solve() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  std::set<int> fac;
  int x = a[1][1];
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      fac.insert(i);
      if (i * i != x) {
        fac.insert(x / i);
      }
    }
  }
  x = a[n][m];
  auto t = fac;
  for (auto y : fac) {
    if (x % y) {
      t.erase(y);
    }
  }       
  fac = t;
  for (auto x : fac | std::views::reverse) {
    // std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j] = 0;
      }
    }
    f[1][1] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1 + (i == 1); j <= m; j++) {
        f[i][j] |= (a[i][j] % x == 0) && (f[i - 1][j] || f[i][j - 1]);
      }
    }
    if (f[n][m]) {
      std::cout << x << '\n';
      return;
    }
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