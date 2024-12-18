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
priority_queue<Node> q;

int pa[101], dis[101];
int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}
set<pair<int, int>> need;
bitset<101> vis;

int main() {
  freopen("data.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++) pa[i] = i, dis[i] = 1 << 30;
  for (int i = 0; i < k; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    need.insert({u, v});
    need.insert({v, u});
  }
  int s, t;
  cin >> s >> t;
  q.push({s, dis[s] = 0});
  for (int i = 1; i <= n; i++)
    for (auto &ed : g[i]) {
      int u = i, v = ed.v;
      if (!need.count({u, v}))
        ed.w = 0;
    }
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u, d = node.d;
    if (u == t) {
      cout << d;
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
  return 0;
}