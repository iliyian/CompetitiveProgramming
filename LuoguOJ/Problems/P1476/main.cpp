#include <bits/stdc++.h>
using namespace std;

int f[101][101];

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  n++;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      f[i][j] = 1 << 29;
    f[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    f[u][v] = -w;
  }
  int ans = -1, ansi, ansj;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  cout << -f[1][n] << '\n';
  for (int i = 1; i <= n; i++)
    if (f[1][n] == f[1][i] + f[i][n])
      cout << i << ' ';
  return 0;
}