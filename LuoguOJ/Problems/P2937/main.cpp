#include <bits/stdc++.h>
using namespace std;

bitset<100> a[100], vis[100];

struct Node {
  int x, y, t, d;
  bool operator < (const Node &b) const {
    return t > b.t;
  }
};
priority_queue<Node> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int w, h, sx, sy, tx, ty;
  cin >> w >> h;
  bool f = false;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c;
      cin >> c;
      a[i][j] = c == '*';
      if (c == 'C') {
        if (f) tx = i, ty = j;
        else sx = i, sy = j, f = true;
      }
    }
  }
  for (int i = 0; i < 4; i++)
    q.push({sx, sy, 0, i});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int x = node.x, y = node.y;
    if (vis[x][y] && !(x == sx && y == sy)) continue;
    vis[x][y] = true;
    if (x == tx && y == ty) {
      cout << node.t;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= h || yy < 0 || yy >= w || a[xx][yy]) continue;
      q.push({xx, yy, node.t + (node.d != i), i});
    }
  }
  cout << -1;
  return 0;
}