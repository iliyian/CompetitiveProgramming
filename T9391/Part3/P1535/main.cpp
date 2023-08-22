// dfs比bfs难写多了

#include <bits/stdc++.h>
using namespace std;

bitset<100> a[100];
int mem[16][100][100];

int sx, sy, tx, ty, n, m, t;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y, int cur) {
  if (mem[cur][x][y] != -1) return mem[cur][x][y];
  if (cur == t) {
    if (x == tx && y == ty) return mem[cur][x][y] = 1;
    return mem[cur][x][y] = 0;
  }
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx < 0 || xx >= n || yy < 0 || yy >= m || a[xx][yy]) continue;
    if (abs(xx - tx) + abs(yy - ty) > t - cur - 1) continue;
    sum += dfs(xx, yy, cur + 1);
  }
  return mem[cur][x][y] = sum;
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      a[i][j] = ch == '*';
      for (int x = 0; x <= t; x++) mem[x][i][j] = -1;
    }
  }
  cin >> sx >> sy >> tx >> ty;
  sx--, sy--, tx--, ty--;
  cout << dfs(sx, sy, 0);
  return 0;  
}