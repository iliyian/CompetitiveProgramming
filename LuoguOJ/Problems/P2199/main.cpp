#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> g, vis;

struct Node {
  int x, y, t;
};
queue<Node> q;

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1}, dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  vis.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    g[i].resize(m + 1);
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      g[i][j] = c == 'X';
    }
  }
  while (true) {
    int sx, sy, tx, ty;
    cin >> tx >> ty >> sx >> sy;
    if (sx == 0) break;

    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) vis[i].assign(m + 1, false);

    q.push({sx, sy, 0});
    bool f = false;
    while (!q.empty()) {
      Node node = q.front(); q.pop();
      int x = node.x, y = node.y;
      
      if (x == tx && y == ty) {
        cout << node.t << '\n';
        f = true;
        break;
      }
      if (vis[x][y]) continue;
      vis[x][y] = true;

      for (int i = 0; i < 8; i++) {
        for (int j = 1;; j++) {
          int xx = x + dx[i] * j, yy = y + dy[i] * j;
          if (xx == tx && yy == ty) {
            cout << node.t << '\n';
            f = true;
            break;
          }
          if (xx <= 0 || xx > n || yy <= 0 || yy > m || g[xx][yy]) break;
        }
        if (f) break;
      }
      if (f) break;

      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx <= 0 || xx > n || yy <= 0 || yy > m || g[xx][yy]) continue;
        q.push({xx, yy, node.t + 1});
      }
    }
    if (!f)
      cout << "Poor Harry\n";
  }
  return 0;
}