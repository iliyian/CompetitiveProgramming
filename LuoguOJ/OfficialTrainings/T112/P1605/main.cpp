#include <bits/stdc++.h>
using namespace std;

int maze[6][6], n, m, t, sx, sy, tx, ty, ans = 0;
bitset<6> vis[6];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
  if (x <= 0 || x > n || y <= 0 || y > m || maze[x][y] || vis[x][y]) return;
  if (x == tx && y == ty) {
    ans++; return;
  }
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    dfs(x + dx[i], y + dy[i]);
  }
  vis[x][y] = 0;
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n >> m >> t;
  cin >> sx >> sy >> tx >> ty;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      maze[i][j] = 0;
  for (int i = 0; i < t; i++) {
    int x, y;
    cin >> x >> y;
    maze[x][y] = 1;
  }
  dfs(sx, sy);
  cout << ans;
  return 0;
}