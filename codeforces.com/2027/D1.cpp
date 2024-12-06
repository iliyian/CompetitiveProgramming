#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1, INT_MAX));
  f[m][n] = 0;
  for (int i = m; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      int p = std::upper_bound(a.begin() + 1, a.end(), a[j] + b[i]) - a.begin() - 1;
      f[i][j] = std::min(f[i][j], f[i][p] + m - i);
    }
  }
  std::cout << f[1][1] << '\n';
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