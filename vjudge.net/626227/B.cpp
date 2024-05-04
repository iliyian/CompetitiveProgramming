#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 1000
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

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  int s = 0, t = n + 2;
  vector<vector<Edge>> g(t + 1);
  auto add = [&](int u, int v, int w, int cap) {
    g[u].push_back({v, w, cap, signed(g[v].size())});
    g[v].push_back({u, -w, 0, signed(g[u].size() - 1)});
  };
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(i, i + 1, inf, inf - a[i]);
  }
  for (int i = 1; i <= m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    add(x, y + 1, c, inf);
  }
  add(s, 1, 0, inf);
  add(n + 1, t, 0, inf);

  vector<int> h(t + 1);
  bitset<N + 10> vis;
  auto spfa = [&]() {
    queue<int> q;
    q.push(s);
    fill(h.begin(), h.end(), inf);
    vis[s] = true, h[s] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      vis[u] = false;
      for (auto &[v, w, cap, id]: g[u]) {
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

  vector<int> dis(t + 1);
  vector<Pre> p(t + 1);
  auto dijkstra = [&]() {
    priority_queue<Node> q;
    fill(dis.begin(), dis.end(), inf);
    vis.reset();
    q.push({s, dis[s] = 0});
    while (!q.empty()) {
      int u = q.top().u; q.pop();
      if (vis[u]) {
        continue;
      }
      vis[u] = true;
      for (int i = 0; i < g[u].size(); i++) {
        auto &[v, w, cap, id] = g[u][i];
        int nw = h[u] - h[v] + w;
        if (cap && dis[v] > dis[u] + nw) {
          dis[v] = dis[u] + nw;
          p[v] = {u, i};
          q.push({v, dis[v]});
        }
      }
    }
    return dis[t] != inf;
  };

  spfa();
  int maxf = 0, minc = 0;
  while (dijkstra()) {
    int minf = inf;
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
    minc += h[t] * minf;
  }
  cout << minc << '\n';

  return 0;
}