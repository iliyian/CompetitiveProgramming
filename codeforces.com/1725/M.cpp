// date: 2024-05-13 21:32:58
// tag: 分层图最短路

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define N ((int)1e5)
using namespace std;

struct Edge {
  int v, w;
};

struct Node {
  int u, d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("M.in", "r", stdin);
  freopen("M.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n * 2 + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y + n].push_back({x + n, w});
  }
  for (int i = 1; i <= n; i++) {
    g[i].push_back({i + n, 0});
  }

  vector<int> dis(n * 2 + 1, inf);
  auto dijkstra = [&](int s) {
    priority_queue<Node> q;
    q.push({s, 0});
    dis[s] = 0;
    bitset<N * 2 + 1> vis;
    while (!q.empty()) {
      int u = q.top().u; q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          q.push({v, dis[v]});
        }
      }
    }
  };
  dijkstra(1);

  for (int i = 2; i <= n; i++) {
    cout << (dis[i + n] == inf ? -1 : dis[i + n]) << ' ';
  }

  return 0;
}