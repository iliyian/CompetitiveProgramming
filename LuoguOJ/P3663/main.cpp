#include <bits/stdc++.h>
using namespace std;

bitset<10000> r[10000];
array<array<int, 100>, 100> vis;
array<int, 10001> ids;

int h(int x, int y) {
  return x + 100 * y;
}

struct Node {
  int x, y;
};
queue<Node> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int N, K, R;

void bfs(int x0, int y0, int id) {
  q.push({x0, y0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y;
    if (vis[x][y]) continue;
    vis[x][y] = id;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= N || yy < 0 || yy >= N || r[h(x, y)][h(xx, yy)]) continue;
      q.push({xx, yy});
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  freopen("data.in", "r", stdin);
  cin >> N >> K >> R;
  for (int i = 0; i < R; i++) {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    sx--, sy--, tx--, ty--;
    r[h(sx, sy)][h(tx, ty)] = r[h(tx, ty)][h(sx, sy)] = true;
  }
  int id = 0;
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < N; j++)
      if (!vis[i][j])
        bfs(i, j, ++id);
  for (int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    ids[vis[x][y]]++;
  }
  int ans = 0;
  for (int i = 1; i <= id; i++)
    for (int j = i + 1; j <= id; j++)
      ans += ids[i] * ids[j];
  cout << ans;
  return 0;
}