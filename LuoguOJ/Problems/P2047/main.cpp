#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int f[101][101];
long long cnt[101][101];
double ans[101];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cnt[i][j] = 0, f[i][j] = inf;
      if (i == j) f[i][j] = 0;
    }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    f[u][v] = f[v][u] = w;
    cnt[u][v] = cnt[v][u] = 1;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (f[i][k] == inf || f[k][j] == inf) continue;
        if (f[i][j] == f[i][k] + f[k][j])
          cnt[i][j] += cnt[i][k] * cnt[k][j];
        else if (f[i][j] > f[i][k] + f[k][j]) {
          f[i][j] = f[i][k] + f[k][j];
          cnt[i][j] = cnt[i][k] * cnt[k][j];
        }
      }
  memset(ans, 0, sizeof(ans));
  for (int v = 1; v <= n; v++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (!cnt[i][j]) continue;
        if (f[i][j] == f[i][v] + f[v][j]) {
          ans[v] += 1.0 * cnt[i][v] * cnt[v][j] / cnt[i][j];
        }
      }
  for (int i = 1; i <= n; i++)
    cout << fixed << setprecision(3) << ans[i] << '\n';
  return 0;
}