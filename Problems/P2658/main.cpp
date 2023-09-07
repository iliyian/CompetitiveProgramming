// -O2 required

#include <bits/stdc++.h>
using namespace std;

int a[500][500], m, n, sx, sy, cnt = 0;
bitset<500> b[500], vis[500];

struct Node {
  int x, y;
};
queue<Node> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool bfs(int h) {
  int cnt0 = 0;
  for (int i = 0; i < m; i++) vis[i].reset();
  while (!q.empty()) q.pop();
  q.push({sx, sy});
  while (!q.empty()) {
    Node node  = q.front(); q.pop();
    int x = node.x, y = node.y;
    if (vis[x][y]) continue;
    vis[x][y] = true;
    if (b[x][y] && ++cnt0 == cnt)
        return true;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= m || yy < 0 || yy >= n || abs(a[xx][yy] - a[x][y]) > h) continue;
      q.push({xx, yy});
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int r = -1, l = 0;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      r = max(r, a[i][j]);
    }
  }
  bool f = false;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      b[i][j] = x;
      if (x) {
        if (!f) {
          sx = i, sy = j, f = false;
        }
        cnt++;
      }
    }
  int ans = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (bfs(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans;
  return 0;
}