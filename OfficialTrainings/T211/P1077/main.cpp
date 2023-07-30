#include <bits/stdc++.h>
using namespace std;

int a[101], dp[101];

int main() {
  int n, W;
  cin >> n >> W;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++)
    cin >> a[i];
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = W; j >= 0; j--) {
      for (int k = 1; k <= min(a[i], j); k++) {
        dp[j] = (dp[j] + dp[j - k]) % 1000007;
      }
    }
  }
  cout << dp[W];
  return 0;
}