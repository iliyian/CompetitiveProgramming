#include <bits/stdc++.h>
using namespace std;

int g[101][101], dp[101][101];

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      g[i][j] = dp[i][j] = 1 << 29;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u][v] = g[v][u] = w;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  int ans = 1 << 30;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {

      for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
          dp[x][y] = g[x][y];

      dp[i][j] = dp[j][i] = 0;

      for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
          dp[x][y] = min(dp[x][y], dp[x][i] + dp[i][y]);
      for (int x = 1; x <= n ; x++)
        for (int y = 1; y <= n; y++)
          dp[x][y] = min(dp[x][y], dp[x][j] + dp[j][y]);

      int temp = 0;
      for (int x = 1; x <= n; x++)
        for (int y = 1; y < x; y++)
          temp += dp[x][y];
      ans = min(ans, temp);
    }
  cout << ans;
  return 0;
}