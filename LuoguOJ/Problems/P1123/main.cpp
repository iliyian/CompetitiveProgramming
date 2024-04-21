// 孤独的 dfs

#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, ans = -1, sum = 0;
array<array<int, 6>, 6> vis, a;

void dfs(int x, int y) {
  if (y == m) {
    dfs(x + 1, 0);
    return;
  }
  if (x == n) {
    ans = max(ans, sum);
    return;
  }
  if (!vis[x][y]) {
    sum += a[x][y];
    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      vis[xx][yy]++;
    }
    dfs(x, y + 1);
    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      vis[xx][yy]--;
    }
    sum -= a[x][y];
  }
  dfs(x, y + 1);
}

void solve() {
  cin >> n >> m;
  ans = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  dfs(0, 0);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}