// date: 2024/02/11 22:38:03
// tag: 一遍过，当然是在借鉴了jiangly的代码的前提下...
// 总体思路就是只考虑向右贪心
// pre[i]即i最后能涉及的，预处理dp[i]即到达i的最小步数，开区间
// cur即当前[i,j]区间右侧循环的位置，mx即包括了cur的当前最远到达的地方，
// 利用已知值尽可能更新dp[n]
//
// 我要学习jiangly码风......

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> pre(n + 1);
  for (int i = 0; i < n; i++) {
    pre[i + 1] = max(pre[i], min(n, i + a[i]));
  }
  vector<int> dp(n + 1, n);
  for (int i = 0, x = 0; ; i = pre[i + 1], x++) {
    dp[i] = x;
    if (i == n) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (j - i + 1 <= a[j]) {
        int cur = j + 1, mx = 0;
        for (int k = i; k < j; k++) {
          mx = max(mx, min(n, k + a[k]));
        }
        for (int k = j + 1, x = dp[i] + 1; ; k = mx, x++) {
          while (cur <= k && cur < n) {
            mx = max(mx, min(n, cur + a[cur]));
            cur++;
          }
          dp[k] = min(dp[k], x);
          if (mx <= k) {
            break;
          }
        }
      }
    }
  }
  cout << dp[n] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}