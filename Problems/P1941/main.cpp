#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(n + 1), y(n + 1), l(n + 1), h(n + 1);
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -inf));
  for (int i = 1; i <= m; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= k; i++) {
    int p;
    cin >> p;
    cin >> l[p] >> h[p];
    for (int j = l[p] + 1; j <= h[p] - 1; j++) {
      dp[p][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j + y[i - 1] <= m) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j + y[i - 1]]);
        vis[i] = true;
      }
      for (int k = 1; k * x[i - 1] < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - k * x[i - 1]] + k);
        
      }
    }
  }
  int minf = inf;
  for (int i = 1; i <= m; i++) {
    if (dp[n][i] > 0) {
      minf = min(minf, dp[n][i]);
    }
  }
  if (minf != inf) {
    cout << minf << '\n';
  } else {
    for (int i = 1; i <= k; i++) {
      for (int j = l[p[i]] + 1; j <= h[p[i]] - 1; j++) {
        if ()
      }
    }
  }

  return 0;
}