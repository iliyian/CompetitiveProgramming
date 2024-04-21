// date: 2024-03-24 15:28:19
// tag: 树形dp
// wa#01: 上界判断错误

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  int mx = log2(n) + 1;
  vector dp(n + 1, vector<int>(mx + 1, inf));
  vector<int> col(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    iota(dp[u].begin() + 1, dp[u].begin() + 1 + mx, 1);
    for (int v : g[u]) {
      if (v == p) continue;
      self(self, v, u);
      for (int i = 1; i <= mx; i++) {
        int mn = inf;
        for (int j = 1; j <= mx; j++) {
          if (j != i) {
            mn = min(mn, dp[v][j]);
          }
        }
        dp[u][i] += mn;
      }
    }
  };
  dfs(dfs, 1, 0);
  int ans = inf;
  for (int i = 1; i <= mx; i++) {
    ans = min(ans, dp[1][i]);
  }
  cout << ans << '\n';

  return 0;
}