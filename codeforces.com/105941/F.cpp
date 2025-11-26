#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  std::vector<std::vector<int>> tag(n + 1, std::vector<int>(m + 1));
  auto bfs = [&](int sx, int sy, int flag) {
    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});
    tag[sx][sy] = flag;
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      for (int d = 0; d < 4; d++) {
        int xx = x + dx[d], yy = y + dy[d];
        if (in(xx, yy) && a[xx][yy] == '.' && tag[xx][yy] != flag) {
          tag[xx][yy] = flag;
          q.push({xx, yy});
        }
      }
    }
  };
  bfs(1, 1, 1);
  if (tag[n][m] == 1) {
    std::cout << 0 << '\n';
    return;
  }
  bfs(n, m, 2);
  std::queue<std::pair<int, int>> q;
  std::vector<std::vector<int>> dis(n + 1, std::vector<int>(m + 1, LLONG_MAX / 3));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (tag[i][j] == 2) {
        dis[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int d = 0; d < 4; d++) {
      int xx = x + dx[d], yy = y + dy[d];
      if (in(xx, yy) && dis[xx][yy] > dis[x][y] + 1) {
        dis[xx][yy] = dis[x][y] + 1;
        q.push({xx, yy});
      }
    }
  }
  int ans = LLONG_MAX / 3;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (tag[i][j] == 1) {
        ans = std::min(ans, dis[i][j]);
      }
    }
  }
  std::cout << ans - 1 << '\n';
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