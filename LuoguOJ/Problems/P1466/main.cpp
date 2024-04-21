#include <bits/stdc++.h>
using namespace std;

int dp[40][800];

int main() {
  int k;
  cin >> k;
  int sum = (k + 1) * k / 2;
  if (sum % 2) {
    cout << 0;
    return 0;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j < sum; j++)
      dp[i][j] = dp[i - 1][j - i] + dp[i - 1][j];
  }
  cout << dp[k][sum / 2];
  return 0;
}