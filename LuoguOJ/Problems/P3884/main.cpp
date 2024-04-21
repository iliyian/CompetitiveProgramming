// 边就是节点与权

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f;
using namespace std;

int f[101][101];

int cnt[101], maxdepth = -1, maxwidth = -1, n;

void dfs(int u, int depth, int pa) {
  maxdepth = max(maxdepth, depth);
  maxwidth = max(maxwidth, ++cnt[depth]);
  for (int v = 1; v <= n; v++) {
    if (f[u][v] == 1 && v != pa)
      dfs(v, depth + 1, u);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n;
  memset(cnt, 0, sizeof(cnt));
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= n; i++)
    f[i][i] = 0;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    f[u][v] = 1;
    f[v][u] = 2;
  }
  dfs(1, 1, 0);
  cout << maxdepth << '\n' << maxwidth << '\n';
  int x, y;
  cin >> x >> y;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  cout << f[x][y];
  return 0;
}