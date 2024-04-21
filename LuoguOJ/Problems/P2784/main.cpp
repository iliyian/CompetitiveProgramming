// 搞不懂为什么可以 dijkstra

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v;
  double w;
};
vector<vector<Edge>> g;

struct Node {
  int u;
  double d;
  bool operator < (const Node &b) const {
    return d < b.d;
  }
};
priority_queue<Node> q;
bitset<5001> vis;
double dis[5001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int N, M, S, T;
  cin >> N >> M >> S >> T;
  g.resize(N + 1);
  for (int i = 1; i <= N; i++) dis[i] = -1;
  for (int i = 0; i < M; i++) {
    int a, b;
    double c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
  }
  q.push({S, 1});
  dis[S] = 1;
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u;
    if (u == T) {
      cout << fixed << setprecision(4) << node.d;
      return 0;
    }
    if (vis[u]) continue;
    vis[u] = false;
    for (auto &ed : g[u]) {
      int v = ed.v;
      double w = ed.w;
      if (dis[v] < dis[u] * w) {
        dis[v] = dis[u] * w;
        q.push({v, dis[v]});
      }
    }
  }
  cout << "orz";
  return 0;
}