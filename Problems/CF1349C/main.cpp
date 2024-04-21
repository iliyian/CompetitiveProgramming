#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n + 1, vector<int>(m + 1)),
    id(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }

  int tot = 0;
  vector<vector<tuple<int, int>>>
    vis(n + 1, vector<tuple<int, int>>(m + 1, {0, inf}));
  auto bfs = [&](int sx, int sy) {
    bool f = false;
    for (int i = 0; i < 4; i++) {
      int x = sx + dx[i], y = sy + dy[i];
      if (x < 1 || x > n || y < 1 || y > m) continue;
      if (a[x][y] == a[sx][sy]) f = true;
    }
    if (!f) return;

    ++tot;
    queue<tuple<int, int>> q;
    queue<tuple<int, int, int >> q2;
    q.push({sx, sy});
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      if (get<0>(vis[x][y]) == tot) continue;
      vis[x][y] = {tot, 0};
      id[x][y] = tot;
      q2.push({x, y, 0});
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if (a[xx][yy] != a[sx][sy] || get<0>(vis[x][y]) == tot) continue;
        q.push({xx, yy});
      }
    }
    while (!q2.empty()) {
      auto [x, y, t] = q2.front(); q2.pop();
      if (get<1>(vis[x][y]) < t) continue;
      vis[x][y] = {tot, t};
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if (get<1>(vis[xx][yy]) <= t) continue;
        q2.push({xx, yy, t + 1});
      }
    }

  };

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!id[i][j]) {
        bfs(i, j);
      }
    }
  }
  for (int i = 0; i < q; i++) {
    int p, sx, sy;
    cin >> sx >> sy >> p;
    if (!tot) {
      cout << a[sx][sy] << '\n';
    } else if (id[sx][sy]) {
      cout << (a[sx][sy] ^ (p & 1)) << '\n';
    } else {
      auto &[nil, t] = vis[sx][sy];
      if (p <= t) {
        cout << a[sx][sy] << '\n';
      } else {
        cout << ((p - t) & 1 ^ a[sx][sy]) << '\n';
      }
    }
  }

  return 0;
}