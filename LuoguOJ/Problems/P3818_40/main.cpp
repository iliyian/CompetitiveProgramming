#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

bitset<1000> a[1000];
array<array<int, 1000>, 1000> vis[2];

struct Node {
  int x, y, t;
  bool used;
};
queue<Node> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int H, W, D, R;

void push(int x, int y, int t, bool used) {
  if (x < 0 || x >= H || y < 0 || y >= W) return;
  if (a[x][y] || vis[used][x][y] != inf) return;
  q.push({x, y, t, used});
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> H >> W >> D >> R;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      a[i][j] = c == '#';
      vis[0][i][j] = vis[1][i][j] = inf;
    }
  push(0, 0, 0, false);
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    bool used = node.used;
    vis[used][x][y] = t;
    if (x == H - 1 && y == W - 1) {
      cout << t;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      push(xx, yy, t + 1, used);
    }
    if (!used) {
      push(x + D, y + R, t + 1, true);
    }
  }
  cout << -1;
  return 0;
}