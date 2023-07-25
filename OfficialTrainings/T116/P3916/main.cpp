#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<vector<int>> adj;

void dfs(int n, int d) {
  if (vis[n]) return;
  vis[n] = d;
  for (int i = 0; i < adj[n].size(); i++)
    dfs(adj[n][i], d);
}

int main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  vis.resize(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
  }
  
  for (int i = n; i >= 1; i--)
    dfs(i, i);
  for (int i = 1; i <= n; i++)
    cout << vis[i] << ' ';
  return 0;
}
