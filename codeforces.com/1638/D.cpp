// date: 2024-04-23 22:09:23
// tag: 逆推，模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  auto check = [&](int x, int y) {
    int cnt = 0, col = a[x][y];
    for (int i = 0; i < 3; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (!in(xx, yy)) return false;
      if (a[xx][yy]) {
        if (col && a[xx][yy] != col) {
          return false;
        }
        col = a[xx][yy];
      }
    }
    return !!col;
  };
  queue<pair<int, int>> q;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= m - 1; j++) {
      if (check(i, j)) {
        q.push({i, j});
      }
    }
  }
  vector<array<int, 3>> ans;
  vector<vector<int>> vis(n + 1, vector<int>(m + 1));
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    int col = a[x][y];
    a[x][y] = 0;
    for (int i = 0; i < 3; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (!in(xx, yy)) continue;
      if (col == 0) col = a[xx][yy];
      a[xx][yy] = 0;
    }
    if (!col) continue;
    ans.push_back({x, y, col});
    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (in(xx, yy) && check(xx, yy)) {
        q.push({xx, yy});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (auto [x, y, c] : ans) {
    cout << x << ' ' << y << ' ' << c << '\n';
  }

  return 0;
}