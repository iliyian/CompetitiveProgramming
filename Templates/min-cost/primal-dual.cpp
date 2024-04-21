// date: 2024-03-12 13:44:31
// tag: 费用流，primal-dual

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 5005
using namespace std;

struct Edge {
  int v, w, cap, id;
};
int n, m, s, t, minc;
vector<vector<Edge>> g;
vector<int> dis, h;
bitset<N> vis;

struct Node {
  int u, d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

struct Pre {
  int p, e;
};
vector<Pre> p;

void spfa() {
  queue<int> q;
  q.push(s);
  vis[s] = true;
  fill(h.begin(), h.end(), inf);
  h[s] = 0;
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
}

bool dijkstra() {
  fill(dis.begin(), dis.end(), inf);
  vis.reset();
  priority_queue<Node> q;
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
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  cin >> n >> m >> s >> t;
  g.resize(n + 1);
  dis.resize(n + 1);
  h.resize(n + 1);
  p.resize(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v, w, c;
    cin >> u >> v >> c >> w;
    g[u].push_back({v, w, c, signed(g[v].size())});
    g[v].push_back({u, -w, 0, signed(g[u].size() - 1)});
  }
  spfa();
  int maxf = 0;
  while (dijkstra()) {
    int minf = inf;
    for (int i = 1; i <= n; i++) {
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
  cout << maxf << ' ' << minc << '\n';

  return 0;
}