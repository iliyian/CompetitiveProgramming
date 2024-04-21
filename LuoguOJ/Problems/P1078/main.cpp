// dijkstra和dfs相比，快得一批

#include <bits/stdc++.h>
using namespace std;

int c[101], a[101][101], dis[101], inf = 0x7fffffff;
int N, K, M, S, T;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

struct Node {
  int u, d;
  bitset<101> visc;
  Node(int u, int d) {this->u = u, this->d = d;}
  bool operator < (const Node &b) const {return d > b.d;}
};
priority_queue<Node> q;

int main() {
  freopen("data.in", "r", stdin);
  cin >> N >> K >> M >> S >> T;
  g.resize(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> c[i], dis[i] = inf;
  dis[S] = 0;
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= K; j++)
      cin >> a[i][j];
  }
  for (int i = 1; i <= M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  q.push(Node(S, 0));
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u, d = node.d;
    auto &visc = node.visc;
    if (visc[c[u]]) continue;
    visc[c[u]] = true;
    if (u == T) {
      cout << d;
      return 0;
    }
    for (auto &ed : g[u]) {
      int v = ed.v, w = ed.w;
      if (a[c[v]][c[u]]) continue;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        Node nd = Node(v, dis[v]); nd.visc = visc;
        q.push(nd);
      }
    }
  }
  cout << -1;
  return 0;
}