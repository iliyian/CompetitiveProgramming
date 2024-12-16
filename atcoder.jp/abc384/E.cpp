// date: 2024-12-14 22:39:26
// tag: 贪心，pq里只放有前途的

#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m, X, p, q;
  std::cin >> n >> m >> X >> p >> q;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  std::vector<std::vector<int>> vis(n + 1, std::vector<int>(m + 1));
  vis[p][q] = 1;
  int s = a[p][q];
  std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> que;
  for (int d = 0; d < 4; d++) {
    int xx = p + dx[d], yy = q + dy[d];
    if (in(xx, yy)) {
      que.push({a[xx][yy], xx, yy});
    }
  }
  std::vector<std::array<int, 3>> tmp;
  while (!que.empty()) {
    auto [d, x, y] = que.top(); que.pop();
    if (vis[x][y]) continue;
    if (d >= (long double)(s) / X) {
      if (que.empty() || que.top()[0] > d) {
        break;
      }
      tmp.push_back({d, x, y});
      continue;
    }
    s += d;
    vis[x][y] = 1;
    while (!tmp.empty()) {
      que.push(tmp.back());
      tmp.pop_back();
    }
    for (int d = 0; d < 4; d++) {
      int xx = x + dx[d], yy = y + dy[d];
      if (in(xx, yy) && !vis[xx][yy]) {
        que.push({a[xx][yy], xx, yy});
      }
    }
  }
  std::cout << s << '\n';
  // std::vector<std::pair<int, int>> cur;
  // std::set<std::pair<int, int>> cur;
  // int s = a[p][q];
  // cur.insert({p, q});
  // vis[p][q] = 1;
  // while (1) {
  //   bool f = false;
  //   for (auto [x, y] : cur) {
  //     for (int d = 0; d < 4; d++) {
  //       int xx = x + dx[d], yy = y + dy[d];
  //       if (in(xx, yy) && !vis[xx][yy] && a[xx][yy] < (long double)(s) / X) {
  //         s += a[xx][yy];
  //         vis[xx][yy] = 1;
  //         cur.insert({xx, yy});
  //         f = true;
  //         // goto end;
  //       }
  //     }
  //   }
  //   // end:
  //   std::set<std::pair<int, int>> ss;
  //   for (auto [x, y] : cur) {
  //     bool f = false;
  //     for (int d = 0; d < 4; d++) {
  //       int xx = x + dx[d], yy = y + dy[d];
  //       if (in(xx, yy) && !vis[xx][yy]) {
  //         f = true;
  //         break;
  //       }
  //     }
  //     if (f) {
  //       ss.insert({x, y});
  //     }
  //   }
  //   cur = ss;
  //   if (!f) {
  //     break;
  //   }
  // }
  // std::cout << s << '\n';
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
