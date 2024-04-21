#include <bits/stdc++.h>
using namespace std;

int iqs[401], eqs[401];
map<int, int> dp;

int main() {
  freopen("data.in", "r", stdin);
  int n, iqsum = 0, iqmin = 0x7fffffff;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> iqs[i] >> eqs[i];
    iqsum += iqs[i];
    iqmin = min(iqmin, iqs[i]);
  }
  for (int i = - 400000; i <= 400000; i++) dp[i] = -1 << 30;
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    if (iqs[i] >= 0) {
      for (int j = 800000; j >= iqs[i]; j--)
        dp[j] = max(dp[j], dp[j - iqs[i]] + eqs[i]);
    } else {
      for (int j = 0; j <= 800000 + iqs[i]; j++)
        dp[j] = max(dp[j], dp[j - iqs[i]] + eqs[i]);
    }
  }
  int ans = -1 << 30;
  for (int i = 400000; i <= 800000; i++)
    ans = max(ans, dp[i] + i - 400000);
  cout << ans;
  return 0;
}