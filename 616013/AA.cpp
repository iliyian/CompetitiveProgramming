#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1}, dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

void solve() {
  vector<vector<char>> a(n * 3, vector<char>(m * 3));
  int sx = 0, sy = 0;
  for (int i = n; i < n * 2; i++) {
    for (int j = m; j < m * 2; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S') {
        sx = i, sy = j;
      }
      for (int k = 0; k < 8; k++) {
        int xx = i + dx[k] * n, yy = j + dy[k] * m;
        a[xx][yy] = a[i][j];
      }
    }
  }
  queue<pair<int, int>> q;
  vector<vector<bool>> vis(n * 3, vector<bool>(m * 3));
  q.push({sx, sy});
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if (vis[x][y]) continue;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n * 3 || yy < 0 || yy >= m * 3 ||
         a[xx][yy] == '#') continue;
      if ((xx != sx || yy != sy) && a[xx][yy] == 'S') {
        cout << "Yes\n";
        return;
      }
      q.push({xx, yy});
    }
  }
  cout << "No\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  while (cin >> n >> m) {
    solve();
  }

  return 0;
}