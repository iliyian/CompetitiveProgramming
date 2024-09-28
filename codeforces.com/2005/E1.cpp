// date: 2024-09-19 21:59:55
// tag: 二维dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int l, n, m;
  std::cin >> l >> n >> m;
  std::vector<int> a(l + 1);
  std::vector<std::vector<int>> b(n + 1, std::vector<int>(m + 1));
  std::vector<int> lst(8);
  int r = l;
  for (int i = 1; i <= l; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= l; i++) {
    if (lst[a[i]]) {
      r = i - 1;
      break;
    }
    lst[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> b[i][j];
    }
  }
  std::vector<std::vector<std::vector<int>>> f(
      n + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(r + 1)));
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      for (int k = r; k >= 1; k--) {
        if (b[i][j] == a[k] &&
            (k == r || i == n || j == m || !f[i + 1][j + 1][k + 1])) {
              f[i][j][k] = 1;
            }
        else if (i + 1 <= n && f[i + 1][j][k]) {
          f[i][j][k] = 1;
        } else if (j + 1 <= m && f[i][j + 1][k]) {
          f[i][j][k] = 1;
        } else {
          f[i][j][k] = 0;
        }
      }
    }
  }
  std::cout << (f[1][1][1] ? "T" : "N") << '\n';
}

signed main() {
  freopen("E1.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}