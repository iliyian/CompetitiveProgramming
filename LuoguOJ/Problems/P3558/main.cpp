#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<array<int, 3>> dp(n + 1, {INT_MAX, INT_MAX, INT_MAX});
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1]
    }
  }
  

  return 0;
}