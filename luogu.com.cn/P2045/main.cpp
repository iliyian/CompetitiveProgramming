// date: 2024-03-13 21:38:04
// tag: 费用流
// wa#01: 忽略了作为流量限制的k，建边忽略了取数和不取两种情况导致的in和out间有重边
// wa#02: 建边忽略了取数和不取两种情况导致的in和out间有重边

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

  int n, k;
  cin >> n >> k;
  int cnt = n * n;
  int s = 0, t = cnt * 2 + 1;
  vector<vector<Edge>> g(t + 1);

  auto add = [&](int u, int v, int cap, int w) {
    g[u].push_back({v, cap, w, signed(g[v].size())});
    g[v].push_back({u, 0, -w, signed(g[u].size() - 1)});
  };

  add(s, 1, k, 0);
  add(cnt * 2, t, k, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      int in = (i - 1) * n + j;
      int out = in + cnt;
      add(in, out, 1, -x); // 最大费用最大流
      add(in, out, inf, 0);
      if (j < n) add(out, in + 1, inf, 0);
      if (i < n) add(out, in + n, inf, 0);
    }
  }

  vector<int> h(t + 1), dis(t + 1);
  vector<bool> vis(t + 1);
  vector<Pre> p(t + 1);
  auto spfa = [&]() {
    fill(h.begin(), h.end(), inf);
    vis[s] = true, h[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
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
  
  auto dijkstra = [&]() {
    fill(vis.begin(), vis.end(), false);
    fill(dis.begin(), dis.end(), inf);
    priority_queue<Node> q;
    q.push({s, dis[s] = 0});
    while (!q.empty()) {
      int u = q.top().u; q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (int i = 0; i < g[u].size(); i++) {
        auto &[v, cap, w, id] = g[u][i];
        int nw = w + h[u] - h[v];
        if (cap && dis[v] > dis[u] + nw) {
          dis[v] = dis[u] + nw;
          p[v] = {u, i};
          q.push({v, dis[v]});
        }
      }
    };

    return dis[t] != inf;
  };

  spfa();
  int maxf = 0, minc = 0;
  while (dijkstra()) {
    for (int i = 0; i <= t; i++) {
      h[i] += dis[i];
    }
    int minf = inf;
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
  cout << -minc << '\n';

  return 0;
}