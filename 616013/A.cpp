#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  vector<string> a(n);
  int sx = 0, sy = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'S') {
        sx = i, sy = j;
      }
    }
  }
  queue<pair<int, int>> q;
  vector<vector<bool>> vis(n * 3, vector<bool>(m * 3));
  q.push({sx, sy});
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if (vis[x + n][y + m]) continue;
    vis[x + n][y + m] = true;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx == sx - n && yy == sy || xx == sx + n && yy == sy
        || xx == sx && yy == sy + n || xx == sx && yy == sy - n) {
          cout << "Yes\n";
          return;
        }
      if (xx < -n || xx >= n * 2 || yy < -m || yy >= m * 2) continue;
      if (a[(xx + n) % n][(yy + m) % m] == '#') continue;
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