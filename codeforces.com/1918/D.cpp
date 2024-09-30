// date: 2024/02/12 01:06:09
// tag: wa#01: 没开 long long
// lambda函数很好地避免了使用全局变量
// 单调递增队列，新数小则pop_back，忽略等于

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<i64> pre(n + 2);
  for (int i = 1; i <= n + 1; i++) {
    pre[i] = pre[i - 1] + a[i];
  }
  auto check = [&](const i64 &s) {
    vector<i64> dp(n + 2, 0x3f3f3f3f3f3f3f3f);
    dp[0] = 0;
    deque<int> q;
    for (int i = 1; i <= n + 1; i++) {
      // 维持最小，移除最大，移除大于号一侧
      while (!q.empty() && dp[i - 1] < dp[q.back()]) {
        q.pop_back();
      }
      q.push_back(i - 1);
      while (pre[i - 1] - pre[q.front()] > s) {
        q.pop_front();
      }
      dp[i] = dp[q.front()] + a[i];
    }
    return dp[n + 1] <= s;
  };
  i64 l = 0, r = pre[n], ans = -1;
  while (l <= r) {
    i64 mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}