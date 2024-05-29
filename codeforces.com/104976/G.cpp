// date: 2024-05-24 15:29:22
// tag: 最短路

#include <bits/stdc++.h>
#define int long long
#define N 3000
#define mod 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
vector<vector<int>> dis(N + 1, vector<int>(N + 1, inf));

struct Node {
  int x, y, d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;
  int sx = -1, sy = -1;
  vector<vector<int>> t(n + 1, vector<int>(m + 1));
  vector<bitset<N + 1>> vis(N + 1);
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    if (sx == -1) {
      sx = x, sy = y;
    }
    t[x][y] = i;
  }
  vector<vector<char>> a(n + 1, vector<char>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  priority_queue<Node> q;
  dis[sx][sy] = 0;
  q.push({sx, sy, dis[sx][sy]});
  while (!q.empty()) {
    auto [x, y, d] = q.top(); q.pop();
    if (vis[x][y]) continue;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
      if (a[xx][yy] == '#') continue;
      // int d = (vis[xx][yy] && (sx != x || sy != y)) ? 
      if (t[xx][yy]) {
        if (dis[xx][yy] > max(dis[x][y], k - t[xx][yy]) + 1) {
          dis[xx][yy] = max(dis[x][y], k - t[xx][yy]) + 1;
          q.push({xx, yy, dis[xx][yy]});
        }
      } else {
        if (dis[xx][yy] > dis[x][y] + 1) {
          dis[xx][yy] = dis[x][y] + 1;
          q.push({xx, yy, dis[xx][yy]});
        }
      }
    }
  }
  unsigned long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      // cout << dis[i][j] << ' ';
      if (dis[i][j] != inf) {
        ans += dis[i][j] * dis[i][j];
      }
    }
    // cout << '\n';
  }
  cout << ans << '\n';

  return 0;
}