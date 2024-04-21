#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, z;
};
vector<vector<Edge>> g;

struct Node {
  int u;
  double cost;
  bool operator < (const Node &b) const {
    return cost > b.cost;
  }
};
priority_queue<Node> q;

bitset<2001> vis;

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }
  int a, b;
  cin >> a >> b;
  q.push({a, 100});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u;
    double cost = node.cost;
    if (u == b) {
      cout << fixed << setprecision(8) << cost;
      return 0;
    }
    if (vis[u]) continue;
    vis[u] = true;
    for (auto &ed : g[u]) {
      int v = ed.v, z = ed.z;
      q.push({v, cost / (1 - z / 100.0)});     
    }
  }
  cout << -1;
  return 0;
}