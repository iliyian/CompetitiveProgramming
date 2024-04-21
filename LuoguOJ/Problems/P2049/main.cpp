#include <bits/stdc++.h>
using namespace std;

int a[100][100];
bitset<100> vis[100][100];

struct Node {
  int x, y, v;
};
queue<Node> q;

set<int> ans;

int dx[] = {0, 1}, dy[] = {1, 0};

int main() {
  freopen("data.in", "r", stdin);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j] %= k;
    }
  }
  q.push({0, 0, a[0][0]});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, v = node.v;
    if (x == n - 1 && y == m - 1) {
      ans.insert(v);
      continue;
    }
    if (vis[x][y][v]) continue;
    vis[x][y][v] = true;
    for (int i = 0; i < 2; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      q.push({xx, yy, v * a[xx][yy] % k});
    }
  }
  cout << ans.size() << '\n';
  for (auto v : ans)
    cout << v << ' ';
  return 0;
}