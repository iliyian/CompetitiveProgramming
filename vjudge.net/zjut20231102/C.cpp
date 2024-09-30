// ~18的数字是状压的最佳提示

#include<bits/stdc++.h>
using namespace std;

char a[305][305];
int sx, sy, tx, ty, T, H, W;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
// int vis[305][305];

struct Node {
  int x, y, d;
};

int dis[305][305];

deque<pair<int, int>> v;

void bfs(int idx) {
  queue<Node> q;
  bitset<305> vis[305];
  q.push({v[idx].first, v[idx].second, 0});
  memset(dis, 0x3f, sizeof(dis));
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, d = node.d;
    if (vis[x][y]) continue;
    vis[x][y] = true;
    dis[x][y] = d;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= H || yy < 0 || yy >= W || a[xx][yy] == '#') continue;
      q.push({xx, yy, d + 1});
    }
  }
}

int f[20][20], dp[20][1 << 20];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int r;
  cin >> H >> W >> T;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S') sx = i, sy = j, v.push_front({i, j});
      if (a[i][j] == 'o') v.push_back({i, j});
      if (a[i][j] == 'G') tx = i, ty = j;
    }
  v.push_back({tx, ty});
  int c = v.size();

  for (int i = 0; i < c; i++) {
    bfs(i);
    for (int j = 0; j < c; j++) {
      f[i][j] = dis[v[j].first][v[j].second];
    }
  }

  memset(dp, 0x3f, sizeof(dp));
  // totally 2^c, and (1 << (i - 1)) stands for every choice's status, therefore no equal
  dp[0][1 << 0] = 0;
  for (int s = 0; s < (1 << c); s++) {
    for (int i = 0; i < c; i++) {
      for (int j = 0; j < c; j++) {
        dp[j][(1 << j) | s] = min(dp[j][(1 << j) | s], dp[i][s] + f[i][j]);
      }
    }
  }

  int ans = -1;
  for (int s = 0; s < (1 << c); s++) {
    if (dp[c - 1][s] <= T)
      ans = max(ans, int(bitset<20>(s).count()));
  }

  cout << (ans < 2 ? -1 : ans - 2);
  return 0;
}