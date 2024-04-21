// 这tmd是个背包

#include <bits/stdc++.h>
using namespace std;

int dp[3000];

int main() {
  // freopen("data.in", "r", stdin);
  int s[4], ans = 0;
  for (int i = 0; i < 4; i++) cin >> s[i];
  int left = 0, right = 0;
  for (int t = 0; t < 4; t++) {
    left = right = 0;
    int tasks[21], taskcnt = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < s[t]; i++) cin >> tasks[taskcnt++];
    sort(tasks, tasks + taskcnt);
    int sum = accumulate(tasks, tasks+taskcnt, 0);
    for (int i = 0; i < taskcnt; i++)
      for (int j = sum / 2; j >= tasks[i]; j--)
        dp[j] = max(dp[j], dp[j - tasks[i]] + tasks[i]);

    ans += sum - dp[sum / 2];
  }
  cout << ans;
  return 0;
}