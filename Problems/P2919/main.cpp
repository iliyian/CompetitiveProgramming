#include <bits/stdc++.h>
using namespace std;

array<array<int, 700>, 700> a, vis;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m;

void dfs(int x, int y, int id) {
  if (vis[x][y]) return;
  vis[x][y] = id;
  bool f = true;
  for (int i = 0; i < 8; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
    if (a[x][y] < a[xx][yy] && !vis[x][y]) {
      f = false;
      break;
    }
  }
  if (f) {
    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      if (a[x][y] >= a[xx][yy])
        dfs(xx, yy, id);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j], v.push_back({i, j});
  int id = 0;
  sort(v.begin(), v.end(), [](const pair<int, int> &c, const pair<int, int> &b) {
    return a[c.first][c.second] > a[b.first][b.second];
  });
  for (auto &i : v) {
    int x = i.first, y = i.second;
    if (!vis[x][y])
      dfs(x, y, ++id);
  }
  cout << id;
  return 0;
}