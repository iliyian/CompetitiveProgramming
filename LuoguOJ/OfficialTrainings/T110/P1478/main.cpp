// 奇了怪了，竟然是贪心，这不是典型背包嘛

#include <bits/stdc++.h>
using namespace std;

int arr[5005], dp[5005];

int main() {
  freopen("data.in", "r", stdin);
  int n, s, a, b;
  cin >> n >> s >> a >> b;
  int h = a + b, cnt = 0;
  for (int i = 0; i < n; i++) {
    int x, w;
    cin >> x >> w;
    if (x <= h) arr[cnt++] = w;
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < cnt; i++) {
    for (int j = s; j >= arr[i]; j--)
      dp[j] = max(dp[j], dp[j - arr[i]] + 1);
  }
  cout << dp[s];
  return 0;
}