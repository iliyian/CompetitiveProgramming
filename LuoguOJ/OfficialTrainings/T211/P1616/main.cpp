// 背包放东西重量不断加大，因此物品会被多次放入

#include <bits/stdc++.h>
using namespace std;

long long dp[10000007];

int times[10005], vs[10005];

int main() {
  int t, m;
  cin >> t >> m;
  for (int i = 0; i < m; i++) {
    int w, v;
    cin >> times[i] >> vs[i];
  }
  for (int i = 0; i < m; i++) {
    for (int j = times[i]; j <= t; j++) {
      dp[j] = max(dp[j], dp[j - times[i]] + vs[i]);
    }
  }
  cout << dp[t];
  return 0;
}