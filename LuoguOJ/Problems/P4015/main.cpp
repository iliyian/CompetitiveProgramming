// date: 2024-03-13 12:12:14
// tag: 最小/大费用最大流

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

  int m, n;
  cin >> m >> n;
  vector<int> a(m + 1), b(n + 1), dis(n + m + 2),
    h(n + m + 2);
  vector<bool> vis(n + m + 2);
  vector<vector<Edge>> g(n + m + 2);
  vector<vector<int>> c(m + 1, vector<int>(n + 1));
  vector<Pre> p(n + m + 2);
  int s = 0, t = n + m + 1;
  auto add = [&](int u, int v, int cap, int w) {
    g[u].push_back({v, cap, w, signed(g[v].size())});
    g[v].push_back({u, 0, -w, signed(g[u].size() - 1)});
  };
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    add(s, i, a[i], 0);
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    add(i + m, t, b[i], 0);
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c[i][j];
      add(i, j + m, inf, c[i][j]);
    }
  }

  auto primal_dual = [&]() {
    auto spfa = [&]() {
      queue<int> q;
      fill(h.begin(), h.end(), inf);
      fill(vis.begin(), vis.end(), false);
      q.push(s);
      h[s] = 0, vis[s] = true;
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
      }
      return dis[t] != inf;
    };

    spfa();
    int maxf = 0, minc = 0;
    while (dijkstra()) {
      for (int i = 0; i <= n + m + 1; i++) {
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
    return minc;
  };
  cout << primal_dual() << '\n';
  g.clear();
  g.resize(n + m + 2);
  for (int i = 1; i <= m; i++) {
    add(s, i, a[i], 0);
  }
  for (int i = 1; i <= n; i++) {
    add(i + m, t, b[i], 0);
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      add(i, j + m, inf, -c[i][j]);
    }
  }
  cout << -primal_dual() << '\n';

  return 0;
}