#include <bits/stdc++.h>
using namespace std;

vector<int> L;
vector<vector<int>> g;
queue<int> q;

int dp[100001], in[100001], n, m;

void toposort() {
  for (int i = 1; i <= n; i++)
    if (!in[i])
      q.push(i);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    L.push_back(u);
    for (auto v : g[u])
      if (!--in[v])
        q.push(v);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    in[v]++;
  }
  toposort();
  for (int i = 1; i <= n; i++) dp[i] = 1;
  for (int i = 0; i < n; i++) {
    int u = L[i];
    for (auto v : g[u])
      dp[v] = max(dp[v], dp[u] + 1);
  }
  for (int i = 1; i <= n; i++)
    cout << dp[i] << '\n';
  return 0;
}