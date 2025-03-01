#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> in, d, out;

queue<int> q;

int main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  in.resize(n + 1);
  out.resize(n + 1);
  d.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    in[v]++;
    out[u]++;
  }
  for (int i = 1; i <= n; i++)
    if (!in[i]) {
      q.push(i);
      d[i] = 1;  // key
    }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      d[adj[u][i]] = (d[u] + d[adj[u][i]]) % 80112002;
      if (!(--in[adj[u][i]]))
        q.push(adj[u][i]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!out[i])
      ans = (ans + d[i]) % 80112002;
  cout << ans;
  return 0;
}