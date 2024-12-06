#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string a, b, c;
  std::cin >> a >> b >> c;
  int n = a.size(), m = b.size();
  a = '#' + a, b = '#' + b, c = '#' + c;
  std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, INT_MIN));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    f[i][0] = std::max(f[i][0], f[i - 1][0] + (a[i] == c[i]));
    for (int j = 1; j <= m; j++) {
      f[0][j] = std::max(f[0][j], f[0][j - 1] + (b[j] == c[j]));
      f[i][j] = std::max(f[i][j], f[i - 1][j] + (a[i] == c[i + j]));
      f[i][j] = std::max(f[i][j], f[i][j - 1] + (b[j] == c[i + j]));
    }
  }
  std::cout << n + m - f[n][m] << '\n';
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