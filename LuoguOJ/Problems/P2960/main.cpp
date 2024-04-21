#include <bits/stdc++.h>
using namespace std;

char a[100][100];

struct Node {
  int x, y, t;
};

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
bitset<100> vis[100];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m, sx, sy;
  cin >> n >> m >> sx >> sy;
  int rest = n * m;
  sx--, sy--;
  for (int j = m - 1; j >= 0; j--) 
    for (int i = 0; i < n; i++) {
      cin >> a[i][j];
      rest -= a[i][j] == '*';
    }
  
  queue<Node> q;
  q.push({sx, sy, 0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    if (vis[x][y]) continue;
    vis[x][y] = true;
    if (!--rest) {
      cout << t;
      return 0;
    }
    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m || a[xx][yy] == '*') continue;
      q.push({xx, yy, t + 1});
    }
  }
  return 0;
}