#include <bits/stdc++.h>
using namespace std;

array<array<char , 30>, 30> a;
bitset<30> vis[30][30][30];

int dx[] = {-1, 0, 1, 0}, dy1[] = {0, 1,  0, -1}, dy2[] = {0, -1, 0, 1};

struct Node {
  int x1, x2, y1, y2, t;
};
queue<Node> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int R, C, sx1, sx2, sy1, sy2;
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> a[i][j];
      switch (a[i][j]) {
        case 'M': sx1 = i, sy1 = j; break;
        case 'G': sx2 = i, sy2 = j; break;
      }
    }
  }
  q.push({sx1, sx2, sy1, sy2, 0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x1 = node.x1, x2 = node.x2, y1 = node.y1, y2 = node.y2, t = node.t;
    if (vis[x1][x2][y1][y2]) continue;
    vis[x1][x2][y1][y2] = true;
    if (a[x1][y1] == 'T' && a[x2][y2] == 'T') {
      cout << t;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int xx1 = x1 + dx[i], xx2 = x2 + dx[i], yy1 = y1 + dy1[i], yy2 = y2 + dy2[i];
      if (xx1 < 0 || xx2 < 0 || xx1 >= R || xx2 >= R || yy1 < 0 || yy2 < 0 || yy1 >= C || yy2 >= C) continue;
      if (a[xx1][yy1] == '#') {
        xx1 -= dx[i], yy1 -= dy1[i];
      }
      if (a[xx2][yy2] == '#') {
        xx2 -= dx[i], yy2 -= dy2[i];
      }
      if (a[xx1][yy1] == 'X' || a[xx2][yy2] == 'X') continue;
      // 前置似乎并没有很大程度上减少内存占用 2.11MB vs 2.30MB
      q.push({xx1, xx2, yy1, yy2, t + 1});
    }
  }
  cout << "no";
  return 0;
}