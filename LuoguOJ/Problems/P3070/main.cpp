#include <bits/stdc++.h>
using namespace std;

char a[50][50];
array<int, 50> id[50], dis[50];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, R, C;

void dfs(int x, int y, int idc) {
  if (x < 0 || x >= R || y < 0 || y >= C || id[x][y] || a[x][y] != 'X') return;
  id[x][y] = idc;
  for (int i = 0; i < 4; i++)
    dfs(x + dx[i], y + dy[i], idc);
}

struct Node {
  int x, y, t;
};

void bfs(int idc) {
  bitset<50> vis[50], visid[50];
  queue<Node> q;
  int d[50][50];
  memset(d, 0x3f, sizeof(d));
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (id[i][j] == idc)
        q.push({i, j, 0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    if (vis[x][y]) continue;
    vis[x][y] = true;
    if (a[x][y] == 'X' && id[x][y] != idc) {
      d[x][y] = t;
      continue;
    }
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= R || yy < 0 || yy >= C || a[xx][yy] == '.') continue;
      q.push({xx, yy, t + (a[xx][yy] == 'S')});
    }
  }
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (a[i][j] == 'X' && id[i][j] != idc)
        dis[idc][id[i][j]] = min(dis[idc][id[i][j]], d[i][j]);
}

int f[1 << 16][16];
void dp(int idc) {
  int lim = (1 << idc) - 1;
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= idc; i++)
    f[1 << i - 1][i] = 0;
  for (int i = 1; i < lim; i++)
    for (int j = 1; j <= idc; j++)
      if ((1 << j - 1) & i)
        for (int k = 1; k <= idc; k++)
          if (j != k && dis[j][k] != 0x3f3f3f3f && !((1 << k - 1) & i))
            f[i | (1 << k - 1)][k] = min(f[i | (1 << k - 1)][k], f[i][j] + dis[j][k]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> R >> C;
  queue<Node> q;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      cin >> a[i][j];

  int idc = 0;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (!id[i][j] && a[i][j] == 'X')
        dfs(i, j, ++idc);

  for (int i = 1; i <= idc; i++)
    dis[i].fill(0x3f3f3f3f), dis[i][i] = 0, bfs(i);

  for (int k = 1; k <= idc; k++)
    for (int i = 1; i <= idc; i++)
      for (int j = 1; j <= idc; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

  dp(idc);
  
  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= idc; i++)
    ans = min(ans, f[(1 << idc) - 1][i]);
  cout << ans;

  return 0;
}