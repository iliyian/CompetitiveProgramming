// 关于取模的奇妙性质是为了避免高精度这件事

#include <bits/stdc++.h>
using namespace std;

array<int, 1000000> dp;

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++)
    dp[i] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= k; j++)
      if (i - j >= 0)
        dp[i] = (dp[i-j] + dp[i]) % 100003;
  cout << dp[n-1];
  return 0;
}