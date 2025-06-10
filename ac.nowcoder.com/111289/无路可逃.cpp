#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2));
  int q;
  std::cin >> q;
  while (q--) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    a[x1][y1]++;
    a[x1][y2 + 1]--;
    a[x2 + 1][y1]--;
    a[x2 + 1][y2 + 1]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      a[i][j] += a[i - 1][j];
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] += a[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      // std::cerr << a[i][j] << " \n"[j == m];
      ans += a[i][j] % 2;
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