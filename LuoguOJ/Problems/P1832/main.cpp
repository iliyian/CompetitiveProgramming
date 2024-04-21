#include <bits/stdc++.h>
using namespace std;

bitset<1001> vis;
int pris[1001], cnt = 0;
long long dp[1001];

int main() {
  int n;
  cin >> n;
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pris[cnt++] = i;
    }
    for (int j = 0; j < cnt; j++) {
      int p = pris[j];
      if (p * i > n) break;
      vis[p * i] = true;
      if (i % p == 0) break;
    }
  }
  for (int i = 0; i < cnt; i++) {
    int p = pris[i];
    for (int j = p; j <= n; j++)
      dp[j] += dp[j - p];
  }
  cout << dp[n];
  return 0;
}