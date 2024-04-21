#include <bits/stdc++.h>
using namespace std;

int l[20001], r[20001], dp[20001][2], d[20001];

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    d[i] = r[i] - l[i];
  }
  dp[0][0] = d[0] + r[0] - 1, dp[0][1] = r[0] - 1;
  for (int i = 1; i < n; i++) {
    dp[i][0] = min(dp[i - 1][0] + abs(l[i - 1] - r[i]), dp[i - 1][1] + abs(r[i - 1] - r[i])) + d[i];
    dp[i][1] = min(dp[i - 1][1] + abs(r[i - 1] - l[i]), dp[i - 1][0] + abs(l[i - 1] - l[i])) + d[i];
  }
  cout << min(dp[n - 1][0] + n - l[n - 1], dp[n - 1][1] + n - r[n - 1]) + n - 1;
  return 0;
}