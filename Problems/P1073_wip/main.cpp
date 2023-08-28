#include <bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;

struct Edge {
  int v, c, w;
};

int a[100001], dis[100001];
bitset<100001> vis[3];
vector<vector<Edge>> g[3];

struct Node {
  int u, c, d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};
priority_queue<Node> q;

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < 3; i++) g[i].resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dis[i] = inf;
    g[0][i].push_back({i, 1, a[i]});
    g[1][i].push_back({i, 2, -a[i]});
  }
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    for (int j = 0; j < 3; j++) {
      g[j][x].push_back({y, j, 0});
      if (z == 2) g[j][y].push_back({x, j, 0});
    }
  }
  q.push({1, 0, 0});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u, c = node.c, d = node.d;
    if (u == n && c == 2) {
      cout << d;
      return 0;
    }
    if (vis[c][u]) continue;
    vis[c][u] = true;
    for (auto &ed : g[c][u]) {
      int v = ed.v, w = ed.w, c = ed.c;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({v, c, dis[v]});
      }
    }
  }
  cout << 0;
  return 0;
}