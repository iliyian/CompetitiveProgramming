// date: 2024-06-17 00:20:39
// tag: dp

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int dx[] = {-1, 0, 1, 0, 0}, dy[] = {0, 1, 0, -1, 0};

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int n, m, k, sx, sy;
  cin >> n >> m >> k >> sx >> sy;
  vector<vector<int>> a(n + 2, vector<int>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int maxt = min(n * m, k);
  int ans = 0;
  vector f(maxt + 2, vector<vector<int>>(n + 2, vector<int>(m + 2, -inf)));
  f[0][sx][sy] = 0;
  for (int t = 1; t <= maxt; t++) {
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= m; y++) {
        for (int d = 0; d < 5; d++) {
          int xx = x + dx[d], yy = y + dy[d];
          f[t][xx][yy] = max(f[t][xx][yy], f[t - 1][x][y] + a[xx][yy]);
          ans = max(ans, f[t][xx][yy]);
        }
        f[maxt + 1][x][y] = max(f[maxt + 1][x][y], f[t][x][y] + (k - t) * a[x][y]);
        ans = max(ans, f[maxt + 1][x][y]);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}