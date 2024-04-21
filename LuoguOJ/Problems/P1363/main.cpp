// date: 2024-03-15 13:46:13
// tag: 一类带模的bfs

#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

struct Node {
  int x, y, mx, my;
};

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
  queue<Node> q;
  q.push({sx, sy, sx, sy});
  vector<vector<bool>> vis(n, vector<bool>(m));
  vector<vector<array<int, 2>>> prv(n, vector<array<int, 2>>(m));
  while (!q.empty()) {
    auto [x, y, mx, my] = q.front(); q.pop();
    if (vis[mx][my]) continue;
    vis[mx][my] = true;
    prv[mx][my] = {x, y};
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      int mxx = (xx % n + n) % n, myy = (yy % m + m) % m;
      if (a[mxx][myy] == '#') continue;
      if (vis[mxx][myy] && (prv[mxx][myy][0] != xx || prv[mxx][myy][1] != yy)) {
        cout << "Yes\n";
        return;
      }
      q.push({xx, yy, mxx, myy});
    }
  }
  cout << "No\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);

  while (cin >> n >> m) {
    solve();
  }

  return 0;
}