#include <bits/stdc++.h>
using namespace std;

char a[500][500];
int r, c;

struct Node {
  int x, y;
};
queue<Node> q;

bitset<500> vis[500];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, ans = 0;

void bfs(int x, int y) {
  q.push({x, y});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y;
    if (vis[x][y]) continue;
    vis[x][y] = true;
    if (a[x][y] == '0') ans--;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= r || yy < 0 || yy >= c || a[xx][yy] == '*') continue;
      q.push({xx, yy});
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> r >> c;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      cin >> a[i][j], ans += a[i][j] == '0';
  for (int i = 0; i < r; i++) {
    if (a[i][0] == '0')
      bfs(i, 0);
    if (a[i][c - 1] == '0')
      bfs(i, c - 1);
  }
  for (int i = 0; i < c; i++) {
    if (a[0][i] == '0')
      bfs(0, i);
    if (a[r - 1][i] == '0')
      bfs(r - 1, i);
  }
  cout << ans;
  return 0;
}