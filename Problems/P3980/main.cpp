// date: 2024-04-10 16:00:25
// tag: 费用流按时间建模
// wa#01: 出点的位置搞错了导致t也搞错了

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Edge {
  int v, cap, w, id;
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

  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  int s = 0, t = n + 2;
  vector<vector<Edge>> g(t + 1);
  auto add = [&](int u, int v, int cap, int w) {
    g[u].push_back({v, cap, w, signed(g[v].size())});
    g[v].push_back({u, 0, -w, signed(g[u].size() - 1)});
  };
  add(s, 1, inf, 0);
  add(n + 1, t, inf, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(i, i + 1, inf - a[i], 0);
  }
  for (int i = 1; i <= m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    add(x, y + 1, inf, c);
  }
  bitset<1005> vis;
  vector<int> h(t + 1);
  vector<Pre> p(t + 1);
  auto spfa = [&]() {
    queue<int> q;
    q.push(s);
    fill(h.begin(), h.end(), inf);
    vis[s] = true, h[s] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      vis[u] = false;
      for (auto &[v, cap, w, id] : g[u]) {
        if (cap && h[v] > h[u] + w) {
          h[v] = h[u] + w;
          if (!vis[v]) {
            q.push(v), vis[v] = true;
          }
        }
      }
    }
  };
  spfa();

  vector<int> dis(t + 1);
  auto dijkstra = [&]() {
    priority_queue<Node> q;
    fill(dis.begin(), dis.end(), inf);
    vis.reset();
    q.push({s, dis[s] = 0});
    while (!q.empty()) {
      int u = q.top().u; q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (int i = 0; i < g[u].size(); i++) {
        auto &[v, cap, w, id] = g[u][i];
        int ww = w + h[u] - h[v];
        if (cap && dis[v] > dis[u] + ww) {
          dis[v] = dis[u] + ww;
          p[v] = {u, i};
          q.push({v, dis[v]});
        }
      }
    }
    return dis[t] != inf;
  };
  int maxf = 0, minc = 0;
  while (dijkstra()) {
    int minf = LLONG_MAX;
    for (int i = 0; i <= t; i++) {
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
  cout << minc << '\n';

  return 0;
}