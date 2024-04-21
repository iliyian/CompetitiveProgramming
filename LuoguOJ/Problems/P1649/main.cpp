#include <bits/stdc++.h>
using namespace std;

bitset<100> a[100], vis[4][100];

struct Node {
  int x, y, t, d;
};
queue<Node> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int N, sx, sy, tx, ty;
  char ch;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> ch;
      a[i][j] = ch == 'x';
      if (ch == 'A') sx = i, sy = j;
      if (ch == 'B') tx = i, ty = j;
    }
  }
  for (int i = 0; i < 4; i++) q.push({sx, sy, 0, i});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t, d = node.d;
    if (x == tx && y == ty) {
      cout << t;
      return 0;
    }
    for (int i = 1;; i++) {
      int xx = x + dx[d] * i, yy = y + dy[d] * i;
      if (xx < 0 || xx >= N || yy < 0 || yy >= N || vis[d][xx][yy] || a[xx][yy]) break;
      q.push({xx, yy, t, d});
      vis[d][xx][yy] = true;
    }
    for (int i = 1; i <= 3; i++) {
      int dd = (d + i) % 4;
      if (vis[dd][x][y]) continue;
      q.push({x, y, t + 1, dd});
      vis[dd][x][y] = true;
    }
  }
  cout << -1;
  return 0;
}