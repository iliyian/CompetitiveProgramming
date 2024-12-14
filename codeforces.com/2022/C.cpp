// date: 2024-12-13 22:22:26
// tag: 简单多状态多层次线性dp

#include <bits/stdc++.h>
#define int long long

bool check(char a, char b, char c) {
  return a == 'A' && b == 'A' || a == 'A' && c == 'A' || b == 'A' && c == 'A';
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> a(3);
  std::cin >> a[1] >> a[2];
  a[1] = '#' + a[1], a[2] = '#' + a[2];
  std::vector<std::array<int, 4>> f(n + 1, {0, 0, 0, 0});
  for (int i = 2; i <= n; i++) {
    f[i][3] = std::max({
      f[i - 1][1] + check(a[1][i], a[2][i], a[2][i - 1]),
      f[i - 1][2] + check(a[1][i], a[2][i], a[1][i - 1]),
      (i >= 3 ? f[i - 3][3] + 
        check(a[1][i - 2], a[1][i - 1], a[1][i]) +
        check(a[2][i - 2], a[2][i - 1], a[2][i]) : 0)
    });
    f[i][1] = std::max({
      f[i - 2][3] + check(a[1][i - 1], a[1][i], a[2][i - 1]),
      (i >= 3 ? f[i - 3][1] +
        check(a[1][i - 2], a[1][i - 1], a[1][i]) +
        check(a[2][i - 3], a[2][i - 2], a[2][i - 1]) : 0),
    });
    f[i][2] = std::max({
      f[i - 2][3] + check(a[1][i - 1], a[2][i], a[2][i - 1]),
      (i >= 3 ? f[i - 3][2] +
        check(a[2][i - 2], a[2][i - 1], a[2][i]) +
        check(a[1][i - 3], a[1][i - 2], a[1][i - 1]) : 0),
    });
  }
  std::cout << f[n][3] << '\n';
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