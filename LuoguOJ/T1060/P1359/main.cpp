#include <bits/stdc++.h>
using namespace std;

int a[201][201], dp[201];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    dp[i] = 1 << 30;
    for (int j = i + 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  dp[1] = 0;
  for (int i = 2; i <= n; i++)
    dp[i] = a[1][i];
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      dp[j] = min(dp[j], a[i][j] + dp[i]);
    }
  }
  cout << dp[n];
  return 0;
}