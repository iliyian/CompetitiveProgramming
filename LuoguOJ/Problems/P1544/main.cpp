#include <bits/stdc++.h>
using namespace std;

long long a[101][101], dp[101][101][5051];

int main() {
  freopen("data.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++) // 如果右边为i，则三角形最右侧上面是没有的
      for (int t = 0; t <= k; t++)
        dp[i][j][t] = -5e9;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      for (int t = 0; t <= k && t <= i; t++) {
        dp[i][j][t] = max(dp[i - 1][j][t], dp[i - 1][j - 1][t]) + a[i][j];
        if (t)
          dp[i][j][t] = max(dp[i][j][t], max(dp[i - 1][j][t - 1], dp[i - 1][j - 1][t - 1]) + a[i][j] * 3);
      }
    }
  }
  long long ans = -5e9;
  for (int j = 1; j <= n; j++)
    for (int t = 0; t <= k; t++)
      ans = max(ans, dp[n][j][t]);
  cout << ans;
  return 0;
}