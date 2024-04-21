#include <bits/stdc++.h>
using namespace std;

bitset<51> a[51], vis[51][51];
bitset<50> b[50];

struct Node {
  int x, y, d, t;
};

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, n, m;
queue<Node> q;

int main() {
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      a[i][j] = x;
    }
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (a[i][j] || a[i + 1][j] || a[i][j + 1] || a[i + 1][j + 1])
        b[i][j] = true;
    }
  }

  int sx, sy, tx, ty, d;
  char ch;
  cin >> sx >> sy >> tx >> ty >> ch;
  sx--, sy--, tx--, ty--;

  switch (ch) {
    case 'S': d = 2; break;
    case 'N': d = 0; break;
    case 'E': d = 1; break;
    case 'W': d = 3; break;
  }

  if (b[sx][sy]) {
    cout << -1;
    return 0;
  }

  q.push({sx, sy, d, 0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, d = node.d, t = node.t;

    if (x == tx && y == ty) {
      cout << node.t;
      return 0;
    }
    if (vis[x][y][d]) continue;
    vis[x][y][d] = true;

    q.push({x, y, (d + 1) % 4, t + 1});
    q.push({x, y, (d + 3) % 4, t + 1});

    for (int i = 1; i <= 3; i++) {
      int xx = x + dx[d] * i, yy = y + dy[d] * i;
      if (xx < 0 || xx >= n - 1|| yy < 0 || yy >= m - 1 || b[xx][yy] || vis[xx][yy][d]) break;
      q.push({xx, yy, d, t + 1});
    }

  }
  cout << -1;
  return 0;
}