// date: 2024-12-13 00:20:19
// tag: 对称性，必须O(1)回答的一类题
// 看似最短路，实则......，正反图正反权性质

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, x;
  std::cin >> n >> m >> x;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  bool f = true;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= m - 1; j++) {
      int q = a[i][j] - a[i + 1][j];
      int w = a[i + 1][j] - a[i + 1][j + 1];
      int e = a[i + 1][j + 1] - a[i][j + 1];
      int r = a[i][j + 1] - a[i][j];
      if (pow(q, x) + pow(w, x) + pow(e, x) + pow(r, x)) {
        f = false;
        break;
      }
    }
  }
  std::vector<std::vector<int>> dis(n + 1, std::vector<int>(m + 1));
  for (int i = 2; i <= n; i++) {
    dis[i][1] = dis[i - 1][1] + pow(a[i - 1][1] - a[i][1], x);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      dis[i][j] = dis[i][j - 1] + pow(a[i][j - 1] - a[i][j], x);
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty; // 所有回路权值和都是0
    if (!f) { // at any cost
      std::cout << "INVALID\n";
      continue;
    }
    std::cout << dis[tx][ty] - dis[sx][sy] << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}