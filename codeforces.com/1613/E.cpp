// date: 2024-04-18 14:23:06
// tag: bfs

#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  int sx, sy;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'L') {
        sx = i, sy = j;
      }
    }
  }
  vector<vector<bool>> vis(n, vector<bool>(m));
  vector<vector<bool>> ok(n, vector<bool>(m));
  vector<vector<int>> siz(n, vector<int>(m));
  auto in = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };
  for (int t = 0; t < 4; t++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        vis[i][j] = false;
        siz[i][j] = 0;
      }
    }
    queue<pair<int, int>> q;
    q.push({sx, sy});
    ok[sx][sy] = true;
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      if (vis[x][y]) continue;
      vis[x][y] = true;
      vector<pair<int, int>> vec;
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!in(xx, yy)) continue;
        if (a[xx][yy] == '#' || a[xx][yy] == 'L' || ok[xx][yy]) continue;
        vec.push_back({xx, yy});
        siz[x][y]++;
      }
      ok[x][y] = siz[x][y] < 2 || a[x][y] == 'L';
      if (ok[x][y]) {
        for (auto [x, y] : vec) {
          q.push({x, y});
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.' && ok[i][j]) {
        cout << '+';
      } else {
        cout << a[i][j];
      }
    }
    cout << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}