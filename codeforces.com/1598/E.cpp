// date: 2024-04-15 16:07:00
// tag: 动态规划，暴力

#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {-1, 0}, dy[] = {0, -1};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> f(n + 2, vector<int>(m + 2)),
    g(n + 2, vector<int>(m + 2)),
    a(n + 2, vector<int>(m + 2));
  int sum = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (a[i][j]) {
        f[i][j] = g[i][j] = 0;
        continue;
      }
      f[i][j] = g[i][j + 1] + 1;
      g[i][j] = f[i + 1][j] + 1;
      sum += f[i][j] + g[i][j];
    }
  }
  int cnt = n * m;
  for (int _ = 1; _ <= q; _++) {
    int x, y;
    cin >> x >> y;
    a[x][y] ^= 1;
    if (a[x][y]) cnt--;
    else cnt++;

    for (int t = 0; t < 2; t++) {
      int i = x, j = y, d = t ^ 1;
      while (i >= 1 && j >= 1) {
        sum -= f[i][j] + g[i][j];

        if (a[i][j]) {
          f[i][j] = g[i][j] = 0;
        } else {
          if (d ^ 1) f[i][j] = g[i][j + 1] + 1; // ?
          else g[i][j] = f[i + 1][j] + 1;
        }

        sum += f[i][j] + g[i][j];

        i += dx[d], j += dy[d];
        d ^= 1;
      }
    }

    cout << sum - cnt << '\n';
  }

  return 0;
}