// 第一次听说反向建图

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};

struct Node {
  int u, dis;
  bool operator < (const Node &b) const {return dis > b.dis;}
};

priority_queue<Node> q;
vector<vector<Edge>> e;
int dis[2001], n, m;
bitset<2001> vis;

void dijkstra(int s) {
  for (int i = s; i <= s + n - 1; i++) {
    dis[i] = 0x7fffffff;
  }
  vis.reset();

  while (!q.empty()) q.pop();
  q.push({s, 0});
  dis[s] = 0;
  
  while (!q.empty()) {
    int u = q.top().u; q.pop();
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
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  e.resize(n * 2 + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    e[v + n].push_back({u + n, w});
  }

  int ans = 0;
  dijkstra(1);
  for (int i = 1; i <= n; i++)
    ans += dis[i];
  dijkstra(1 + n);
  for (int i = n + 1; i <= n * 2; i++)
    ans += dis[i];
  cout << ans;
  return 0;
}