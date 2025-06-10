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
  int sx, sy, tx, ty;
  std::cin >> sx >> sy >> tx >> ty;
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> q;
  std::vector<std::vector<int>> dis(n + 1, std::vector<int>(m + 1, LLONG_MAX / 3));
  q.push({dis[sx][sy] = 0, sx, sy});
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  while (!q.empty()) {
    auto [d, x, y] = q.top(); q.pop();
    if (dis[x][y] != d) continue;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (in(xx, yy) && a[xx][yy] != '#') {
        if (dis[xx][yy] > dis[x][y]) {
          q.push({dis[xx][yy] = dis[x][y], xx, yy});
        }
      }
      for (int z = 2; z <= 3; z++) {
        if (in(xx, yy)) {
          if (dis[xx][yy] > dis[x][y] + 1) {
            q.push({dis[xx][yy] = dis[x][y] + 1, xx, yy});
          }
        }
        xx += dx[i], yy += dy[i];
      }
    }
  }
  std::cout << dis[tx][ty] << '\n';
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