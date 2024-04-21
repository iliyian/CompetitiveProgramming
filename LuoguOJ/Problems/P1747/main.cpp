#include <bits/stdc++.h>
using namespace std;

bitset<20> vis[20];

struct Node {
  int x, y, t;
};
queue<Node> q;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2, -2, 2, 2, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1, 2, 2, -2, -2};

void solve(int sx, int sy) {
  q.push({sx, sy, 0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    if (x == 0 && y == 0) {
      cout << t << '\n';
      while (!q.empty()) q.pop();
      return;
    }
    for (int i = 0; i < 12; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= 20 || yy < 0 || yy >= 20 || vis[xx][yy]) continue;
      q.push({xx, yy, t + 1});
      vis[xx][yy] = true;
    }
  }
  cout << -1 << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--, y1--, x2--, y2--;
  solve(x1, y1);
  for (int i = 0; i < 20; i++) vis[i].reset();
  solve(x2, y2);
  return 0;
}