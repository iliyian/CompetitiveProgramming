// date: 2025-04-21 00:43:56
// tag: 疑似比较少见的基于计数的分类讨论？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
    for (int j = 1; j <= m; j++) {
      sum += a[i][j] == '.';
    }
  }
  std::vector<int> r(n + 1), c(m + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      r[i] += a[i][j] == '.';
      c[j] += a[i][j] == '.';
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (r[i] >= 4) ans += r[i] * (r[i] - 1) * (r[i] - 2) * (r[i] - 3);
    if (r[i] >= 3) {
      int cnt = 0;
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '.') {
          ans += (r[i] - 1) * (r[i] - 2) * 2 * (c[j] - 1);
        }
      }
    }
    if (r[i] >= 2) {
      int cnt = 0;
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '.') {
          ans -= (c[j] - 1) * (c[j] - 1);
          cnt += c[j] - 1;
        }
      }
      ans += cnt * cnt;
    }
  }
  for (int j = 1; j <= m; j++) {
    if (c[j] >= 4) ans += c[j] * (c[j] - 1) * (c[j] - 2) * (c[j] - 3);
    if (c[j] >= 3) {
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i][j] == '.') {
          ans += (c[j] - 1) * (c[j] - 2) * 2 * (r[i] - 1);
        }
      }
    }
    if (c[j] >= 2) {
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i][j] == '.') {
          ans -= (r[i] - 1) * (r[i] - 1);
          cnt += r[i] - 1;
        }
      }
      ans += cnt * cnt;
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