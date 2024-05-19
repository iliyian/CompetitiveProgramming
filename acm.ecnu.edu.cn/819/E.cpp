#include <bits/stdc++.h>
#define int long long
#define N 500
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n + 1, vector<char>(m + 1));
  int ox = -1, oy = -1, Xx = -1, Xy = -1, sx = -1, sy = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'O') {
        ox = i, oy = j;
      }
      if (a[i][j] == 'X') {
        Xx = i, Xy = j;
      }
      if (a[i][j] == 'S') {
        sx = i, sy = j;
      }
    }
  }
  auto in = [&](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };

  auto check = [&](int x1, int y1, int x2, int y2, bool f) {  
    vector<bitset<N + 1>> vis(N + 1);
    queue<array<int, 2>> q;
    q.push({x1, y1});
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      if (vis[x][y]) continue;
      vis[x][y] = true;
      if (x == x2 && y == y2) {
        return true;
      }
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!in(xx, yy) || a[xx][yy] == '#') continue;
        if (f) {
          int xx2 = x + dx[(i + 2) % 4], yy2 = y + dy[(i + 2) % 4];
          if (!in(xx2, yy2) || a[xx2][yy2] == '#') continue;
        }
        if (vis[xx][yy]) continue;
        q.push({xx, yy});
      }
    }
    return false;
  };

  for (int i = 0; i < 2; i++) {
    int xx = ox + dx[i], yy = oy + dy[i];
    int xx2 = ox + dx[i + 2], yy2 = oy + dy[i + 2];
    if (in(xx, yy) && check(xx, yy))
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