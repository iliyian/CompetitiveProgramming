#include <bits/stdc++.h>
using namespace std;

char a[1500][1500];

struct Color {
  bool vis;
  int x, y;
  Color() {
    x = -1, y = -1, vis = false;
  }
  Color(int x, int y, bool vis) {
    this->x = x, this->y = y, this->vis = vis;
  }
} color[1500][1500];

struct Node {
  int x, y, rx, ry;
};

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, n, m;

void solve() {
  int sx, sy;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      color[i][j] = Color();

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S')
        sx = i, sy = j;
    }
    
  queue<Node> q;
  q.push({sx, sy, sx, sy});

  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, rx = node.rx, ry = node.ry;
    auto &c = color[x][y];
    if (c.vis && (c.x != rx || c.y != ry)) {
      cout << "Yes\n";
      return;
    }
    if (c.vis && c.x == rx && c.y == ry) continue;
    c = Color(rx, ry, true);

    for (int i = 0; i < 4; i++) {
      int xx = (x + dx[i] + n) % n, yy = (y + dy[i] + m) % m;
      if (a[xx][yy] == '#') continue;
      q.push({xx, yy, rx + dx[i], ry + dy[i]});
    }
  }
  cout << "No\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  while (cin >> n >> m) solve();
  return 0;
}