#include <bits/stdc++.h>
using namespace std;

int n, m;
bitset<65> g[51][51];
int f[51][51];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  memset(f, 0x3f, sizeof(f));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    f[u][v] = 1;
    g[u][v][0] = true;
  }
  
  for (int t = 0; t < 64; t++)
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          if (g[i][k][t] && g[k][j][t])
            g[i][j][t + 1] = true, f[i][j] = 1;

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  
  cout << f[1][n];

  return 0;
}