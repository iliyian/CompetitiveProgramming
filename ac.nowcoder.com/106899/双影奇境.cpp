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
  std::vector<std::vector<int>> dis(n + 1, std::vector<int>(m + 1, LLONG_MAX / 3));
  std::vector<std::vector<int>> id(n + 1, std::vector<int>(m + 1, -1));
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  int tot = 0;
  auto bfs = [&](int sx, int sy, int idx) {
    dis[sx][sy] = 0;
    id[sx][sy] = idx;
    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (in(xx, yy) && dis[xx][yy] == LLONG_MAX / 3 && a[xx][yy] == '.') {
          dis[xx][yy] = dis[x][y] + 1;
          id[xx][yy] = idx;
          q.push({xx, yy});
        }
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.' && id[i][j] == -1) {
        bfs(i, j, ++tot);
      }
    }
  }
  auto canonly = [&](int sx, int sy, int tx, int ty) {
    // assert(sx == tx || sy == ty);
    for (int i = 0; i < 4; i++) {
      int xx = sx + dx[i], yy = sy + dy[i];
      if (xx != tx || yy != ty) {
        if (in(xx, yy) && a[xx][yy] == '.') {
          return false;
        }
      }
    }
    return true;
  };
  auto near = [&](int sx, int sy, int tx, int ty) {
    return sx == tx && std::abs(sy - ty) == 1 || sy == ty && std::abs(sx - tx) == 1;
  };
  int q;
  std::cin >> q;
  while (q--) {
    int xm, ym, xz, yz, xe, ye;
    std::cin >> xm >> ym >> xz >> yz >> xe >> ye;
    if (id[xm][ym] != id[xz][yz] || id[xm][ym] != id[xe][ye]) {
      std::cout << "No\n";
      continue;
    }
    if (dis[xm][ym] % 2 != dis[xz][yz] % 2) {
      std::cout << "No\n";
      continue;
    }
    if (near(xm, ym, xe, ye) && near(xz, yz, xe, ye)) {
      std::cout << "Yes\n";
      continue;
    }
    if (near(xm, ym, xe, ye)) {
      if (canonly(xm, ym, xe, ye)) {
        std::cout << "No\n";
      } else {
        std::cout << "Yes\n";
      }
      continue;
    } else if (near(xz, yz, xe, ye)) {
      if (canonly(xz, yz, xe, ye)) {
        std::cout << "No\n";
      } else {
        std::cout << "Yes\n";
      }
      continue;
    }
    std::cout << "Yes\n";
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