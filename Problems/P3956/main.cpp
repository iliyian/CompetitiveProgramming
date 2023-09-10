#include <bits/stdc++.h>
using namespace std;

array<array<int, 100>, 100> a, vis;

struct Node {
  int x, y, cost;
  bool used, pre;
  bool operator < (const Node &b) const {
    return cost > b.cost;
  }
};
priority_queue<Node> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    a[i].fill(-1), vis[i].fill(0x3f3f3f3f);
  for (int i = 0; i < n; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    x--, y--;
    a[x][y] = c;
  }
  q.push({0, 0, 0, false});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int x = node.x, y = node.y, cost = node.cost;
    bool used = node.used;
    if (x == m - 1 && y == m - 1) {
      cout << cost;
      return 0;
    }
    if (vis[x][y] <= cost) continue;
    vis[x][y] = cost;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= m || yy < 0 || yy >= m) continue;
      if (a[xx][yy] < 0) {
        if (!used) {
          q.push({xx, yy, cost + 2, true, bool(a[x][y])});
        }
      } else {
        bool p = used ? node.pre : a[x][y];
        q.push({xx, yy, cost + (a[xx][yy] == p ? 0 : 1), false});
      }
    }
  }
  cout << -1;
  return 0;
}