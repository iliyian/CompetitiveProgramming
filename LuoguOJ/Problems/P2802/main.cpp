#include <bits/stdc++.h>
using namespace std;

int a[9][9];

struct Node {
  int x, y, t, life;
};
queue<Node> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bitset<9> vis[7][9];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m, sx, sy;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 2)
        sx = i, sy = j;
    }
  q.push({sx, sy, 0, 6});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t, life = node.life;
    if (life == 0) continue;
    if (a[x][y] == 3) {
      cout << t;
      return 0;
    }
    if (vis[life][x][y]) continue;
    vis[life][x][y] = true;
    if (a[x][y] == 4) life = 6;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m || a[xx][yy] == 0) continue;
      q.push({xx, yy, t + 1, life - 1});
    }
  }
  cout << -1;
  return 0;
}