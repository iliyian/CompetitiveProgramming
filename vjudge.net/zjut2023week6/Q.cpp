#include <bits/stdc++.h>
#define N 100005
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
int dis[N];
bitset<N> vis;

void dijkstra(int s) {
  priority_queue<Node> q;
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  q.push({s, dis[s]});
  while (!q.empty()) {
    int u = q.top().u; q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto &[v, w] : g[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({v, dis[v]});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("Q.in", "r", stdin);
  int n, m, s;
  cin >> n >> m >> s;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }
  dijkstra(s);
  for (int i = 1; i <= n; i++)
    cout << dis[i] << ' ';
  return 0;
}