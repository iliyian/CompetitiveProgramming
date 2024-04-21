// date: 2024-04-05 19:07:58
// tag: 二分图最大/小权匹配

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Edge {
  int v, w, cap, id;
};

struct Node {
  int u, d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

struct Pre {
  int p, e;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  int s = 0, t = n * 2 + 1;
  int f = 1;

  vector<vector<int>> c(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c[i][j];
    }
  }
  for (int _ = 0; _ < 2; _++) {

  vector<vector<Edge>> g(t + 1);
  auto add = [&](int u, int v, int w, int cap) {
    g[u].push_back({v, w, cap, signed(g[v].size())});
    g[v].push_back({u, -w, 0, signed(g[u].size() - 1)});
  };
  for (int i = 1; i <= n; i++) {
    add(s, i, 0, 1);
    add(i + n, t, 0, 1);
    for (int j = 1; j <= n; j++) {
      int x = c[i][j] * f;
      add(i, j + n, x, 1);
    }
  }
  vector<int> h(t + 1);
  vector<bool> vis(t + 1);
  auto spfa = [&]() {
    queue<int> q;
    q.push(s);
    fill(h.begin(), h.end(), inf);
    h[s] = 0, vis[s] = true;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      vis[u] = false;
      for (auto &[v, w, cap, id] : g[u]) {
        if (cap && h[v] > h[u] + w) {
          h[v] = h[u] + w;
          if (!vis[v]) {
            q.push(v);
            vis[v] = true;
          }
        }
      }
    }
  };
  spfa();

  vector<int> dis(t + 1);
  vector<Pre> p(t + 1);
  auto dijkstra = [&]() {
    priority_queue<Node> q;
    fill(dis.begin(), dis.end(), inf);
    fill(vis.begin(), vis.end(), false);
    q.push({s, dis[s] = 0});
    while (!q.empty()) {
      int u = q.top().u; q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (int i = 0; i < g[u].size(); i++) {
        auto &[v, w, cap, id] = g[u][i];
        int nw = w + h[u] - h[v];
        if (cap && dis[v] > dis[u] + nw) {
          dis[v] = dis[u] + nw;
          p[v] = {u, i};
          q.push({v, dis[v]});
        }
      }
    }
    return dis[t] != inf;
  };

  int maxf = 0, minc = 0;
  while (dijkstra()) {
    int minf = inf;
    for (int i = s; i <= t; i++) {
      h[i] += dis[i];
    }
    for (int i = t; i != s; i = p[i].p) {
      minf = min(minf, g[p[i].p][p[i].e].cap);
    }
    for (int i = t; i != s; i = p[i].p) {
      auto &e = g[p[i].p][p[i].e];
      e.cap -= minf;
      g[i][e.id].cap += minf;
    }
    maxf += minf;
    minc += minf * h[t];
  }
  cout << minc * f << '\n';

  f = -1;
  }
  return 0;
}