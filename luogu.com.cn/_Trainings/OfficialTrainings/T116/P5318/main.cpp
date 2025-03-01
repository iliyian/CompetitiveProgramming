#include <bits/stdc++.h>
using namespace std;

bitset<100010> vis;
vector<vector<int>> adj;

void dfs(int n) {
  if (vis[n]) return;
  vis[n] = true;
  cout << n << ' ';
  for (int i = 0; i < adj[n].size(); i++)
    dfs(adj[n][i]);
}

queue<int> q;

void bfs(int n) {
  q.push(n);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    cout << u << ' ';
    for (int i = 0; i < adj[u].size(); i++) {
      q.push(adj[u][i]);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; i++)
    sort(adj[i].begin(), adj[i].end());
  dfs(1);
  vis.reset();
  cout << '\n';
  bfs(1);
  return 0;
}