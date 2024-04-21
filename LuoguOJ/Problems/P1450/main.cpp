// date: 2024-02-27 19:02:50
// tag: 状态压缩动态规划，完全背包，容斥

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  vector<int> c(4);
  for (int i = 0; i < 4; i++) {
    cin >> c[i];
  }
  int t;
  cin >> t;

  while (t--) {
    vector<int> d(4);
    for (int i = 0; i < 4; i++) {
      cin >> d[i];
    }
    int s;
    cin >> s;
    vector<int> dp(s + 1);
    dp[0] = 1;
    for (int i = 0; i < 4; i++) {
      for (int j = c[i]; j <= s; j++) {
        dp[j] += dp[j - c[i]];
      }
    }
    int ans = 0;
    for (int i = 0; i < (1 << 4); i++) {
      bool f = 0;
      int sum = s;
      for (int j = 0; j < 4; j++) {
        if ((i >> j) & 1) {
          sum -= c[j] * (d[j] + 1);
          f ^= 1;
        }
      }
      if (sum >= 0) {
        ans += (f ? -1 : 1) * dp[sum];
      }
    }
    cout << ans << '\n';
  }

  return 0;
}