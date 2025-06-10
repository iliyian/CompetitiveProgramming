#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<int> r(n + 1), c(m + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    str = '#' + str;
    for (int j = 1; j <= m; j++) {
      a[i][j] = str[j] - '0';
      cnt += a[i][j];
      r[i] += a[i][j];
      c[j] += a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (r[i] == m - 1 && c[j] == n - 1 && a[i][j] == 0 && cnt == m - 1 + n - 1) {
        std::cout << "YES\n";
        return;
      }
    }
  }
  if (!cnt) {
    std::cout << "YES\n";
    return;
  }
  // for (int i = 1; i <= n; i++) {
  //   if (r[i] == m && cnt == m) {
  //     std::cout << "YES\n";
  //     return;
  //   }
  // }
  // for (int i = 1; i <= m; i++) {
  //   if (c[i] == n && cnt == n) {
  //     std::cout << "YES\n";
  //     return;
  //   }
  // }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (r[i] + r[j] == cnt && r[i] == m && r[j] == m) {
        std::cout << "YES\n";
        return;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      if (c[i] + c[j] == cnt && c[i] == n && c[j] == n) {
        std::cout << "YES\n";
        return;
      }
    }
  }
  std::cout << "NO\n";
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