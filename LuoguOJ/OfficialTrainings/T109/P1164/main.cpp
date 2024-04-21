#include <bits/stdc++.h>
using namespace std;

int a[105], dp[105];

int main() {
  int n, m;
  cin >> n >> m;
  memset(a, 0, sizeof(a));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = m; j >= a[i]; j--) {
      dp[j] += dp[j - a[i]];
    }
  }
  cout << dp[m];
}