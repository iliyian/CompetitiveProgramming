#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};

struct Node {
  int u, dis;
  bool operator < (const Node &b) const {return dis > b.dis;}
};

vector<vector<Edge>> g;
bitset<101> vis;
priority_queue<Node> q;

int a[10001], dis[101][101], n, m;

void dijkstra(int s) {
  for (int i = 1; i <= n; i++)
    dis[s][i] = 0x7fffffff;
  dis[s][s] = 0;
  vis.reset();
  q.push({s, dis[s][s]});
  while (!q.empty()) {
    int u = q.top().u; q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto ed : g[u]) {
      int v = ed.v, w = ed.w;
      if (dis[s][v] > dis[s][u] + w) {
        dis[s][v] = dis[s][u] + w;
        q.push({v, dis[s][v]});
      }
    }
  }
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int w;
      cin >> w;
      if (i == j) continue;
      g[i].push_back({j, w});
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    dijkstra(i);
  }
  for (int i = 0; i < m - 1; i++)
    ans += dis[a[i]][a[i + 1]];
  cout << ans;
  return 0;
}