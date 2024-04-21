#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> e;

struct Node {
  int u, dis;
  bool operator < (const Node &b) const {return dis > b.dis;}
};
priority_queue<Node> q;

bitset<100001> vis;
int dis[100001], n, m, Q;

void dijkstra(int s) {
  for (int i = 1; i <= n; i++) dis[i] = 1 << 30;
  vis.reset();
  dis[s] = 0;
  q.push({s, dis[s]});
  while (!q.empty()) {
    int u = q.top().u; q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] ^ w) {
        dis[v] = dis[u] ^ w;
        if (!vis[v]) q.push({v, -dis[v]});
      }
    }
  }
}

int main() {
  cin >> n >> m >> Q;
  e.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    dijkstra(x);
    cout << dis[y];
  }
  return 0;
}