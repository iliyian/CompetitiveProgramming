#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
  int v, w;
};

struct Node {
  int u, dis;
  bool operator < (const Node &b) const {
    return dis > b.dis;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  vector<int> dis(n + 1);
  vector<bool> vis(n + 1);
  priority_queue<Node> q;
  dis[1] = 0;
  q.push({1, 0});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u;
    if (vis[u]) continue;
    vis[u] = true;
    if (u == n) {
      
    }
    for (auto [v, w] : adj[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        prv[v] = u;
        q.push({v, dis[v]});
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}