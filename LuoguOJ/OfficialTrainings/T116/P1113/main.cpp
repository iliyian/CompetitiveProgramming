// 又是反向建图

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> lens;
vector<int> dp;

int dfs(int n) {
  if (dp[n]) return dp[n];
  for (int i = 0; i < adj[n].size(); i++) {
    dp[n] = max(dp[n], dfs(adj[n][i]));
  }
  dp[n] += lens[n];
  return dp[n];
}

int ans = 0;

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  adj.resize(n + 1);
  dp.resize(n + 1, 0);
  lens.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    int u, len, v;
    cin >> u >> len;
    lens[u] = len;
    while (cin >> v) {
      if (!v) break;
      adj[v].push_back(u);
    }
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dfs(i));
  }
  cout << ans;
  return 0;
}