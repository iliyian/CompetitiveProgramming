// 注意不可到达的特殊处理

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};

queue<int> q;
vector<int> L;
vector<vector<Edge>> adj;
int in[1505], dp[1505], inf = 1 << 30;

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;

  memset(in, 0, sizeof(in));
  for (int i = 1; i <= n; i++) dp[i] = -inf;
  adj.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    in[v]++;
  }
  for (int i = 1; i <= n; i++)
    if (!in[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    L.push_back(u);
    for (int i = 0; i < adj[u].size(); i++) {
      if (--in[adj[u][i].v] == 0)
        q.push(adj[u][i].v);
    }
  }

  dp[1] = 0;
  for (int i = 0; i < L.size(); i++) {
    int u = L[i];
    for (int j = 0; j < adj[u].size(); j++) {
      int &v = adj[u][j].v;
      dp[v] = max(dp[v], dp[u] + adj[u][j].w);
    }
  }
  cout << (dp[n] == -inf ? -1 : dp[n]);

  return 0;
}