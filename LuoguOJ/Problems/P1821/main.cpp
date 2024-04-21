#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

struct Node {
  int u, d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};
int dis[2001];
bitset<2001> vis;
priority_queue<Node> q;

int main() {
  freopen("data.in", "r", stdin);
  int n, m, x;
  cin >> n >> m >> x;
  g.resize(2 * n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v + n].push_back({u + n, w});
  }
  for (int i = 1; i <= 2 * n; i++) dis[i] = 1 << 30;
  q.push({x, 0});
  q.push({x + n, 0});
  dis[x] = dis[x + n] = 0;
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u;
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
  int maxn = -1;
  for (int i = 1; i <= n; i++)
    maxn = max(maxn, dis[i] + dis[i + n]);
  cout << maxn;
  return 0;
}