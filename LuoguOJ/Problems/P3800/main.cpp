// date: 2024-02-28 22:37:35
// tag: wa#01: 忘了初始化deque时插入的时候也要保持单调

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k, t;
  cin >> n >> m >> k >> t;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 0; i < k; i++) {
    int r, c, v;
    cin >> r >> c >> v;
    a[r][c] = v;
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    deque<int> q;
    for (int j = 1; j <= t + 1; j++) {
      while (!q.empty() && dp[i - 1][q.back()] < dp[i - 1][j])
        q.pop_back();
      q.push_back(j);
    }
    for (int j = 1; j <= m; j++) {
      for (int k = q.back() + 1; k <= min(m, j + t); k++) {
        while (!q.empty() && dp[i - 1][q.back()] < dp[i - 1][k])
          q.pop_back();
        q.push_back(k);
      }
      while (!q.empty() && q.front() < j - t)
        q.pop_front();
      dp[i][j] = dp[i - 1][q.front()] + a[i][j];
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = max(ans, dp[n][i]);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _ = 1;

  while (_--) {
    solve();
  }

  return 0;
}