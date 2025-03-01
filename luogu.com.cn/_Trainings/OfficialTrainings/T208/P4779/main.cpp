#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};

struct Node {
  int u, d;
  bool operator < (const Node &b) const {return d > b.d;}
};

vector<vector<Edge>> e;
bitset<100001> vis;
priority_queue<Node> q;
int dis[100001];

int main() {
  int n, m, s;
  cin >> n >> m >> s;
  e.resize(n + 1);
  for (int i = 1; i <= n; i++) dis[i] = 1 << 30;
  dis[s] = 0;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
  }
  q.push({s, 0});
  while (!q.empty()) {
    int u = q.top().u; q.pop();
    if (vis[u]) continue; // 优先队列不保证后面的不影响前面
    vis[u] = true;
    for (auto ed : e[u]) {
      if (vis[ed.v]) continue;
      if (dis[u] + ed.w < dis[ed.v]) {
        dis[ed.v] = dis[u] + ed.w;
        q.push({ed.v, dis[ed.v]});
      }
    }
  }
  for (int i = 1; i <= n; i++)
    cout << dis[i] << ' ';
  return 0;
}