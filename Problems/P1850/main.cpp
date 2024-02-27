// date: 2024/02/26 14:52:45
// tag: wa#01: signed integer overflow，未考虑重边
// wa#02: 未考虑重边
// wa#03: 未考虑重边

#include <bits/stdc++.h>
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

void solve() {
  int n, m, v, e;
  cin >> n >> m >> v >> e;
  vector<int> c(n + 1), d(n + 1);
  vector<double> k(n + 1);
  vector<vector<int>> adj(v + 1, vector<int>(v + 1, inf));
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  for (int i = 1; i <= n; i++)
    cin >> d[i];
  for (int i = 1; i <= n; i++)
    cin >> k[i];
  for (int i = 0; i < e; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x][y] = adj[y][x] = min(adj[x][y], w);
  }

  for (int k = 1; k <= v; k++) {
    for (int i = 1; i <= v; i++) {
      for (int j = 1; j <= v; j++) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
  for (int i = 1; i <= v; i++) {
    adj[i][i] = adj[0][i] = adj[i][0] = 0;
  }

  vector<vector<array<double, 2>>>
    dp(n + 1, vector<array<double, 2>>(m + 1, {inf, inf}));
  dp[1][0][0] = dp[1][1][1] = 0;
  for (int i = 2; i <= n; i++) {
    int c1 = c[i - 1], c2 = c[i], d1 = d[i - 1], d2 = d[i];
    dp[i][0][0] = dp[i - 1][0][0] + adj[c1][c2];
    for (int j = 1; j <= min(i, m); j++) {
      dp[i][j][0] = min({dp[i][j][0], dp[i - 1][j][0] + adj[c1][c2],
        dp[i - 1][j][1] + adj[d1][c2] * k[i - 1] + adj[c1][c2] * (1 - k[i - 1])});
      dp[i][j][1] = min({dp[i][j][1], dp[i - 1][j - 1][0] + adj[c1][d2] * k[i] + adj[c1][c2] * (1 - k[i]),
       dp[i - 1][j - 1][1] + adj[d1][d2] * k[i] * k[i - 1] + adj[c1][c2] * (1 - k[i]) * (1 - k[i - 1])
        + adj[d1][c2] * k[i - 1] * (1 - k[i]) + adj[c1][d2] * (1 - k[i - 1]) * k[i]});
    }
  }
  double ans = inf;
  for (int i = 0; i <= m; i++) {
    ans = min({ans, dp[n][i][1], dp[n][i][0]});
  }
  cout << fixed << setprecision(2) << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}