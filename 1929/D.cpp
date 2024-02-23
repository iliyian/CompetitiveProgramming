// date: 2024/02/22 20:32:26
// tag: 标准树形dp，基于根节点和父节点唯一性，
// 树形dp记录的信息常常与根节点和父节点有关

#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  vector<array<int, 3>> dp(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    dp[u][0] = dp[u][1] = 1;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
      dp[u][1] *= (dp[v][0] + dp[v][1]) % mod, dp[u][1] %= mod;
      dp[u][2] += (dp[v][2] + dp[v][1]) % mod, dp[u][2] %= mod;
    }
  };
  dfs(dfs, 1, 0);
  cout << (dp[1][0] + dp[1][1] + dp[1][2]) % mod << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}