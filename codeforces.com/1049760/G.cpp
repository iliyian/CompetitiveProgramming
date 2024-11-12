#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<int>> ans(n + 1, std::vector<int>(m + 1, INT_MAX));
  std::vector<std::vector<int>> vis(n + 1, std::vector<int>(m + 1));
  int sx, sy;
  std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, std::greater<>> q;
  // std::queue<std::array<int, 4>> q;
  for (int i = 1; i <= k; i++) {
    int x, y;
    std::cin >> x >> y;
    a[x][y] = i;
    if (i == 1) {
      sx = x, sy = y;
    }
  }
  q.push({0, sx, sy});
  // for (int i = 1; i <= k; i++) {
  //   q.push({0, sx, sy, i});
  // }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      std::cin >> ch;
      if (a[i][j] > 0) continue;
      a[i][j] = (ch == '.' ? 0 : -1);
    }
  }
  auto in = [&](int x, int y) -> bool {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  while (!q.empty()) {
    auto [x, y] = q.top(); q.pop();
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (!in(xx, yy) || vis[xx][yy]) continue;
      q.push({x + dx[i], y + dy[i]});
    }
  }
  unsigned long long res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      res += ans[i][j] * ans[i][j];
      std::cout << ans[i][j] << " \n"[j == m];
    }
  }
  std::cout << res << '\n';
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