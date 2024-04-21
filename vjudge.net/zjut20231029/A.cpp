#include <bits/stdc++.h>
#define int long long
using namespace std;

int g[101][101];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> g[i][j];
      if (g[i][j] == 0) g[i][j] = 0x3f3f3f3f;
    }
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int s, t;
    cin >> s >> t;
    s %= n, t %= n;
    if (s == 0) s = n;
    if (t == 0) t = n;
    if (g[s][t] != 0x3f3f3f3f) cout << g[s][t] << '\n';
    else cout << -1 << '\n';
  }
  return 0;
}