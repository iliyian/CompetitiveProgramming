// 分层图dp法

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> e;

struct Node {
  int u, dis, cnt;
  bool operator < (const Node &b) const {return dis > b.dis;}
};
priority_queue<Node> q;

bitset<11> vis[10001];
int dis[10001][11];

int main() {
  freopen("data.in", "r", stdin);
  int n, m, k, s, t;
  cin >> n >> m >> k >> s >> t;
  
  e.resize(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++)
      dis[i][j] = 1 << 30;
  
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }

  dis[s][0] = 0;
  q.push({s, 0, 0});
  while (!q.empty()) {
    int u = q.top().u, cnt = q.top().cnt; q.pop();
    if (vis[u][cnt]) continue;
    vis[u][cnt] = true;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (cnt < k && dis[v][cnt + 1] > dis[u][cnt]) {
        dis[v][cnt + 1] = dis[u][cnt];
        if (!vis[v][cnt + 1]) q.push({v, dis[v][cnt + 1], cnt + 1});
      }
      if (dis[v][cnt] > dis[u][cnt] + w) {
        dis[v][cnt] = dis[u][cnt] + w;
        if (!vis[v][cnt]) q.push({v, dis[v][cnt], cnt});
      }
    }
  }

  int ans = 1 << 30;
  for (int i = 0; i <= k; i++)
    ans = min(ans, dis[t][i]);
  cout << ans;
  return 0;
}