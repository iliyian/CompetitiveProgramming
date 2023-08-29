#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

struct Node {
  int u, d;
  bool operator < (const Node &b) const {return d > b.d;}
};
priority_queue<Node> q;
bitset<2501> vis;
int dis[2501];

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  for (int i = 1; i <= n; i++) dis[i] = 1 << 30;
  dis[1] = 0;
  q.push({1, 0});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u;
    if (u == n) {
      cout << node.d;
      return 0;
    }
    if (vis[u]) continue;
    vis[u] = true;
    for (auto &ed : g[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({v, dis[v]});
      }
    }
  }
  cout << -1;
  return 0;
}