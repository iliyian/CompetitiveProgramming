#include <bits/stdc++.h>
using namespace std;

int f[101][101];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < 101; i++)
    memset(f[i], 0x3f, sizeof(f[i])), f[i][i] = 0;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    f[u][v] = f[v][u] = w;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      cout << f[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}