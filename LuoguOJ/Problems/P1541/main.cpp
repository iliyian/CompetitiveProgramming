#include <bits/stdc++.h>
using namespace std;

int cnt[5], a[351], dp[41][41][41][41];

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  dp[0][0][0][0] = a[1];
  for (int i = 0; i <= cnt[1]; i++)
    for (int j = 0; j <= cnt[2]; j++)
      for (int k = 0; k <= cnt[3]; k++)
        for (int l = 0; l <= cnt[4]; l++) {
          int cur = i * 1 + j * 2 + k * 3 + l * 4 + 1;
          if (i) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + a[cur]);
          if (j) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + a[cur]);
          if (k) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + a[cur]);
          if (l) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + a[cur]);
        }
  cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
  return 0;
}