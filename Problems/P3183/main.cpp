#include <bits/stdc++.h>
using namespace std;

int in[100001], dp[100001];
queue<int> q;
vector<vector<int>> g;

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  memset(in, 0, sizeof(in));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    in[v]++;
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++)
    if (!in[i] && !g[i].empty())
      q.push(i), dp[i] = 1;
  int ans = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (g[u].empty()) ans += dp[u];
    else for (auto v : g[u]) {
      dp[v] += dp[u];
      if (!--in[v])
        q.push(v);
    }
  }
  cout << ans;
  return 0;
}