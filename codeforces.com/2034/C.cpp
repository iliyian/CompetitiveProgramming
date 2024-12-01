#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

std::string urdl = "URDL";

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> pa(n * m + 1), siz(n * m + 1, 1);
  std::vector<int> free(n * m + 1);
  std::iota(pa.begin(), pa.end(), 0);

  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    siz[y] += siz[x];
    pa[x] = y;
    free[y] |= free[x];
  };

  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      std::cin >> ch;
      a[i][j] = urdl.find(ch);
    }
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };

  std::queue<std::pair<int, int>> q;

  for (int i = 1; i <= m; i++) {
    if (a[1][i] == 0) q.push({1, i});
    if (a[n][i] == 2) q.push({n, i});
  }
  for (int i = 1; i <= n; i++) {
    if (a[i][1] == 3) q.push({i, 1});
    if (a[i][m] == 1) q.push({i, m});
  }

  std::vector<std::vector<int>> vis(n + 1, std::vector<int>(m + 1));
  int ans = 0;
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if (vis[x][y]) continue;
    vis[x][y] = 1;
    free[(x - 1) * m + y] = 1;
    for (int d = 0; d < 4; d++) {
      int xx = x + dx[d], yy = y + dy[d];
      if (in(xx, yy) && a[xx][yy] != -1) {
        int xxx = xx + dx[a[xx][yy]], yyy = yy + dy[a[xx][yy]];
        if (xxx == x && yyy == y && !vis[xx][yy]) {
          q.push({xx, yy});
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == -1) {
        bool f = true;
        for (int d = 0; d < 4; d++) {
          int xx = i + dx[d], yy = j + dy[d];
          if (in(xx, yy) && !free[(xx - 1) * m + yy]) {
            f = false;
            break;
          }
        }
        free[(i - 1) * m + j] = f;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans += !free[(i - 1) * m + j];
    }
  }
  std::cout << ans << '\n';

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     int cur = (i - 1) * m + j;
  //     if (a[i][j] == std::string::npos) {
  //       continue;
  //     }
  //     int xx = i + dx[a[i][j]], yy = j + dy[a[i][j]];
  //     if (!in(xx, yy)) {
  //       free[cur] = 1;
  //       continue;
  //     }
  //     int nxt = (xx - 1) * m + yy;
  //     merge(cur, nxt);
  //   }
  // }
  // int ans = 0;
  // // for (int i = 1; i <= n; i++) {
  // //   for (int j = 1; j <= m; j++) {
  // //     if (a[i][j] == std::string::npos) continue;
  // //     int id = (i - 1) * m + j;
  // //     id = find(find, id);
  // //     if (!free[id] && siz[id] > ) {
  // //       ans++;
  // //     }
  // //   }
  // // }
  // std::queue<std::pair<int, int>> q;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     if (a[i][j] == std::string::npos) {
  //       for (int d = 0; d < 4; d++) {
  //         int xx = i + dx[d], yy = j + dy[d];
  //         if (!in(xx, yy)) continue;
  //         int id = (xx - 1) * m + yy;
  //         id = find(find, id);
  //         if (!free[id]) {
  //           q.push({i, j});
  //           break;
  //         }
  //       }
  //     }
  //   }
  // }
  // std::vector<std::vector<int>> vis(n + 1, std::vector<int>(m + 1));
  // while (!q.empty()) {
  //   auto [x, y] = q.front(); q.pop();
  //   if (vis[x][y]) continue;
  //   vis[x][y] = true;
  //   ans++;
  //   for (int d = 0; d < 4; d++) {
  //     int xx = x + dx[d], yy = y + dy[d];
  //     if (in(xx, yy) && !vis[xx][yy] && a[xx][yy] == std::string::npos) {
  //       q.push({xx, yy});
  //     }
  //   }
  // }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     if (a[i][j] != std::string::npos) {
  //       int id = (i - 1) * m + j;
  //       if (!free[find(find, id)]) {
  //         ans++;
  //       }
  //     }
  //   }
  // }
  // std::cout << ans << '\n';
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