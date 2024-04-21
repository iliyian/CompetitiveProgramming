#include <bits/stdc++.h>
using namespace std;

int a[101][101], dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bitset<101> vis[101];

struct Node {
  int x, y, t;
};

void solve() {
  int n, m, sx, sy;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 3) sx = i, sy = j;
    }
  queue<Node> q;
  q.push({sx, sy, 0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    if (a[x][y] == 4) {
      cout << t << '\n';
      return;
    }
    if (vis[x][y]) continue;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m || a[x][y] == 1) continue;
      q.push({xx, yy, t + 1});
    }
  }
  cout << "unreachable" << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("3.in", "r", stdin);
  freopen("3.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}