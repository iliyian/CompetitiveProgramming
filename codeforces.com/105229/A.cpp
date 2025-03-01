#include <bits/stdc++.h>
#define int long long

// int a[20000];
int ans[102][102];

void solve() {
  int n, m;
  std::cin >> n >> m;
  n++, m++;
  memset(ans, 0, sizeof(ans));
  // std::vector<std::vector<int>> ans(n + 1, std::vector<int>(m + 1));
  // std::vector<int> ans(n * m);
  // auto in = [&](int &x, int &y) {
  //   return x >= 0 && x < n && y >= 0 && y < m;
  // };
  int x1 = 0, y1 = 0;
  for (int a = 0; a < n * m; a++) {
    int x2 = x1, y2 = y1 + 1;
    if (y2 == m) y2 = 0, x2++;
    for (int b = a + 1; b < n * m; b++) {
  // for (int x1 = 0; x1 < (n + 1) / 2; x1++) {
    // for (int y1 = 0; y1 < (m + 1) / 2; y1++) {
      // int x1 = a / m, y1 = a % m, x2 = b / m, y2 = b % m;
      int x3 = x2 + y1 - y2, y3 = y2 + x2 - x1, x4 = x1 + y1 - y2, y4 = y1 + x2 - x1;
      // int c = x3 * m + y3, d = x4 * m + y4;
      // if (in(x3, y3) && in(x4, y4)) {
      if (x3 >= 0 && x3 < n && y3 >= 0 && y3 < m && x4 >= 0 && x4 < n && y4 >= 0 && y4 < m) {
        ans[x1][y1]++, ans[x2][y2]++, ans[x3][y3]++, ans[x4][y4]++;
        // ans[a]++, ans[b]++, ans[c]++, ans[d]++;
      }
      y2++;
      if (y2 == m) y2 = 0, x2++;
    }
    y1++;
    if (y1 == m) y1 = 0, x1++;
  }
  int cur = 0 ;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << ans[i][j] / 2 << ' ';
      // std::cout << ans[cur++] << ' ';
    }
    std::cout << '\n';
  }
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