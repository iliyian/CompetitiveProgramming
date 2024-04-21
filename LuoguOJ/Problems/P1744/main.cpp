#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v;
  double w;
};
vector<vector<Edge>> g;

int x[101], y[101];
bitset<101> vis;

struct Node {
  int u;
  double d;
  bool operator < (const Node &b) const {return d > b.d;}
};
priority_queue<Node> q;
double dis[101];

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    dis[i] = 1 << 30;
  }
  int m;
  cin >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;
    double d = sqrt((x[s] - x[t]) * (x[s] - x[t]) + (y[s] - y[t]) * (y[s] - y[t]));
    g[s].push_back({t, d});
    g[t].push_back({s, d});
  }
  int s, t;
  cin >> s >> t;
  q.push({s, 0});
  dis[s] = 0;
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u;
    if (u == t) {
      cout << fixed << setprecision(2) << node.d;
      return 0;
    }
    if (vis[u]) continue;
    vis[u] = true;
    for (auto &ed : g[u]) {
      int v = ed.v;
      double w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({v, dis[v]});
      }
    }
  }
  cout << -1;
  return 0;
}