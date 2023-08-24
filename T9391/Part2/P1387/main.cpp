#include <bits/stdc++.h>
using namespace std;

array<array<int, 100>, 100> dp;

int main() {
  freopen("data.in", "r", stdin);
  int n, m, ans = -1;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      if (x) dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
  return 0;
}