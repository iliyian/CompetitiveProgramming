#include <bits/stdc++.h>
using namespace std;

int h[50], t[50], k[50], dp[401][401];

int main() {
  int maxh, maxt, n;
  cin >> maxh >> maxt >> n;
  for (int i = 0; i < maxh; i++)
    memset(dp[i], 0, sizeof(dp[i]));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
    cin >> h[i] >> t[i] >> k[i];
  for (int i = 0; i < n; i++)
    for (int j = maxh; j >= h[i]; j--)
      for (int g = maxt; g >= t[i]; g--)
        dp[j][g] = max(dp[j][g], dp[j - h[i]][g - t[i]] + k[i]);
  cout << dp[maxh][maxt];
  return 0;
}