// Johnson底层也是dijkstra，注意不需要跑n次，每次在u==t return，而只需要跑1次即可
// 顺便这题数据19MB,我还是删了吧

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

struct Node {
  int u;
  long long d;
  bool operator < (const Node &b) const {return d > b.d;}
};
priority_queue<Node> q;

bitset<2000001> vis;
long long dis[2000001];
int n, m;

long long dijkstra(int s) {
  vis.reset();
  for (int i = 1; i <= 2 * n; i++) dis[i] = 0x7fffffff;
  dis[s] = 0;
  q.push({s, 0});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u, d = node.d;
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
  return accumulate(dis + s, dis + s + n, 0ll);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  g.resize(2 * n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v + n].push_back({u + n, w});
  }
  cout << dijkstra(1) + dijkstra(n + 1);
  return 0;
}