#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> t(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<int>> d(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<std::array<int, 4>>> dis(n + 1, std::vector<std::array<int, 4>>(m + 1, {LLONG_MAX / 3, LLONG_MAX / 3, LLONG_MAX / 3, LLONG_MAX / 3}));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> t[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> d[i][j];
    }
  }
  // std::cout << dis[n][m][2] << '\n';
  std::priority_queue<std::array<int, 4>, std::vector<std::array<int, 4>>, std::greater<>> q;
  q.push({dis[1][1][1] = t[1][1], 1, 1, 1});
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  std::vector<std::vector<std::array<std::array<int, 3>, 4>>> prv(n + 1, std::vector<std::array<std::array<int, 3>, 4>>(m + 1));
  while (!q.empty()) {
    auto [dist, x, y, dir] = q.top(); q.pop();
    if (dis[x][y][dir] != dist) continue;
    for (int i = 0; i < 4; i++) {
      if (i == dir) continue;
      if (dis[x][y][i] > dis[x][y][dir] + d[x][y]) {
        dis[x][y][i] = dis[x][y][dir] + d[x][y];
        prv[x][y][i] = {x, y, dir};
        q.push({dis[x][y][i], x, y, i});
      }
    }
    int xx = x + dx[dir], yy = y + dy[dir];
    if (!in(xx, yy)) continue;
    int w = t[xx][yy];
    if (dis[xx][yy][dir] > dis[x][y][dir] + w) {
      dis[xx][yy][dir] = dis[x][y][dir] + w;
      prv[xx][yy][dir] = {x, y, dir};
      q.push({dis[xx][yy][dir], xx, yy, dir});
    }
  }
  std::cout << dis[n][m][2] << '\n';
  int x = n, y = m, dir = 2;
  while (x != 1 || y != 1 || dir != 1) {
    std::cerr << x << ' ' << y << ' ' << dir << ' ' << dis[x][y][dir] << '\n';
    auto [xx, yy, d] = prv[x][y][dir];
    x = xx, y = yy, dir = d;
  }
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