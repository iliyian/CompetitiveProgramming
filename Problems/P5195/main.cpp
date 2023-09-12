// bfs 中 vis 前置似乎往往更妥当，性能差距无几

#include <bits/stdc++.h>
using namespace std;

int a[1000][1000], dis[1000][1000], ava[1000][1000];

struct Node {
  int x, y, t;
};

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int W, H;

void bfs(int sx, int sy, bool f) {
  queue<Node> q;
  q.push({sx, sy, 0});
  bitset<1000> viss[1000];
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    if (viss[x][y]) continue;
    viss[x][y] = true;
    if (a[x][y] == 4) {
      dis[x][y] += t, ava[x][y]++;
      continue;
    }
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= H || yy < 0 || yy >= W || a[xx][yy] == 1) continue;
      if (f && a[xx][yy] == 3) continue;
      q.push({xx, yy, t + 1});
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int x2, y2, x3, y3, x4, y4;
  cin >> W >> H;
  vector<pair<int, int>> v;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
      switch (a[i][j]) {
        case 2: x2 = i, y2 = j; break;
        case 3: x3 = i, y3 = j; break;
        case 4: v.push_back({i, j}), dis[i][j] = 0, ava[i][j] = 0;
      }
    }

  int ans = 0x3f3f3f3f;
  bfs(x2, y2, true);
  bfs(x3, y3, false);
  for (auto &i : v) {
    if (ava[i.first][i.second] == 2)
      ans = min(ans, dis[i.first][i.second]);
  }
  cout << ans;

  return 0;
}