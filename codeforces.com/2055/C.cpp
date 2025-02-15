// date: 2025-01-20 12:57:16
// tag: 分类讨论

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string str;
  std::cin >> str;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<int> rs(n + 1), cs(m + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
      rs[i] += a[i][j];
      cs[j] += a[i][j];
    }
  }
  int x = 1, y = 1;
  for (int i = 0; i < n + m - 1; i++) {
    if (str[i] == 'R') {
      a[x][y] = -cs[y];
      rs[x] += a[x][y];
      y++;
    } else {
      a[x][y] = -rs[x];
      cs[y] += a[x][y];
      x++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cout << a[i][j] << " \n"[j == m];
    }
  }
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