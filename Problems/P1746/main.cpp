// 原来vis赋值可以前置到for循环,提升很大
// 原来这就是为什么即使push前检测了vis，在之后仍然要检测的原因

#include <bits/stdc++.h>
using namespace std;

bitset<1000> a[1000], vis[1000];

struct Node {
  int x, y, t;
};
queue<Node> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  char ch;
  int sx, sy, tx, ty, N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> ch;
      a[i][j] = ch == '1';
    }
  }
  cin >> sx >> sy >> tx >> ty;
  sx--, sy--, tx--, ty--;
  q.push({sx, sy, 0});
  if (a[sx][sy]) {
    cout << -1;
    return 0;
  }
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    if (x == tx && y == ty) {
      cout << t;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= N || yy < 0 || yy >= N || a[xx][yy] || vis[xx][yy]) continue;
      q.push({xx, yy, t + 1});
      vis[xx][yy] = true;
    }
  }
  cout << -1;
  return 0;
}