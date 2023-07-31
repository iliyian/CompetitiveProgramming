#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> e;
bitset<10001> vis;
int dis[10001];

struct Node {
  int u, d;
  bool operator < (const Node &b) const {return d > b.d;}
};
priority_queue<Node> q;

int main() {
  freopen("data.in", "r", stdin);
  int n, m, s;
  cin >> n >> m >> s;
  e.resize(n + 1);
  for (int i = 1; i <= n; i++) dis[i] = (1LL << 31) - 1;
  dis[s] = 0;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
  }
  q.push({s, 0});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u;
    if (vis[u]) continue;
    vis[u] = true;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (vis[v]) continue;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({v, dis[v]});
      }
    }
  }
  for (int i = 1; i <= n; i++)
    cout << dis[i] << ' ';
  return 0;
}