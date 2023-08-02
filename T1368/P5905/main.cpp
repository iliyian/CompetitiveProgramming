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
priority_queue<Node> pq;
queue<int> q;

bitset<3001> vis;
int dis[3001], h[3001], cnt[3001], n, m;
const int inf = 1e9;

void spfa() {
  for (int i = 1; i <= n; i++) {
    h[i] = 1e9;
    e[0].push_back({i, 0});
  }
  memset(cnt, 0, sizeof(cnt));
  
  h[0] = 0;
  q.push(0), vis[0] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vis[u] = false;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (h[v] > h[u] + w) {
        h[v] = h[u] + w;
        cnt[v]++; // 这里似乎不能用 cnt[v] = cnt[u] + 1;
        if (cnt[v] >= n) {
          cout << -1;
          exit(0);
        }
        if (!vis[v]) q.push(v), vis[v] = true;
      }
    }
  }
}

void dijkstra(int s) {
  for (int i = 1; i <= n; i++) dis[i] = inf;
  vis.reset();

  dis[s] = 0;
  pq.push({s, dis[s]});
  while (!pq.empty()) {
    int u = pq.top().u; pq.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (!vis[v]) pq.push({v, dis[v]});
      }
    }
  }
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  e.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
  }

  spfa();
  
  for (int u = 1; u <= n; u++)
    for (auto &ed : e[u])
      ed.w += h[u] - h[ed.v];
      
  for (int i = 1; i <= n; i++) {
    dijkstra(i);
    long long ans = 0;
    for (long long j = 1; j <= n; j++) {
      if (dis[j] == inf) ans += j * inf;
      else ans += j * (dis[j] + h[j] - h[i]);
    }
    cout << ans << '\n';
  }
  
  return 0;
}