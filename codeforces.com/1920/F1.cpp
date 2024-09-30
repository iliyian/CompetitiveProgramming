// date: 2024-03-21 00:43:19
// tag: bfs，二分
// tuple的访问也是O(1)的，会在编译时计算offset

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F1.in", "r", stdin);
  freopen("F1.out", "w", stdout);

  int n, m, Q;
  cin >> n >> m >> Q;
  vector<vector<char>> a(n + 1, vector<char>(m + 1));
  vector<tuple<int, int>> vols, isls;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'v') {
        vols.push_back({i, j});
      } else if (a[i][j] == '#') {
        isls.push_back({i, j});
      }
    }
  }
  vector<vector<int>> dis(n + 1, vector<int>(m + 1, inf));
  int maxd = -1;
  queue<tuple<int, int, int>> q;
  for (auto &[x, y] : vols) {
    q.push({x, y, 0});
  }
  while (!q.empty()) {
    auto [x, y, d] = q.front(); q.pop();
    if (dis[x][y] <= d) continue;
    dis[x][y] = d;
    maxd = max(maxd, d);
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 1 || xx > n || yy < 1 || yy > m || dis[xx][yy] <= d)
        continue;
      q.push({xx, yy, d + 1});
    }
  }
  auto check = [&](int sx, int sy, int mid) {
    queue<tuple<int, int>> q;
    q.push({sx, sy});
    vector<vector<bool>> tag(n + 1, vector<bool>(m + 1));
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      if (dis[x][y] < mid || tag[x][y] || a[x][y] == '#') continue;
      tag[x][y] = true;
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if (tag[xx][yy] || a[xx][yy] == '#' || dis[xx][yy] < mid) continue;
        q.push({xx, yy});
      }
    }
    for (auto &[x, y] : isls) {
      q.push({x, y});
      break;
    }
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      if (vis[x][y] || tag[x][y]) continue;
      vis[x][y] = true;
      for (int i = 0; i < 8; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if (tag[xx][yy] || vis[xx][yy]) continue;
        if (xx == 1 || xx == n || yy == 1 || yy == m) {
          return false;
        }
        q.push({xx, yy});
      }
    }
    return true;
  };
  for (int _ = 0; _ < Q; _++) {
    int x, y;
    cin >> x >> y;
    int l = 0, r = maxd, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(x, y, mid)) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    cout << ans << '\n';
  }

  return 0;
}