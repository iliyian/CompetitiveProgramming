#include <bits/stdc++.h>
using namespace std;

int win[1003], lose[1003], use[1003];
long long dp[1003];

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++)
    cin >> lose[i] >> win[i] >> use[i];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = x; j >= use[i]; j--)
      dp[j] = max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
    for (int j = use[i] - 1; j >= 0; j--)
      dp[j] += lose[i];
  }
  cout << dp[x] * 5;
  return 0;
}