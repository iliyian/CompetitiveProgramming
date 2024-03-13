// date: 2024-03-12 21:57:49
// tag: 费用流
// wa#01: 考虑成简单的贪心和模拟了

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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), dis(n + 2), h(n + 2), pre(n + 2);
  vector<vector<Edge>> g(n + 2);
  vector<bool> vis(n + 2);
  vector<Pre> p(n + 2);
  int s = 0, t = n + 1;
  auto add = [&](int u, int v, int cap, int w) {
    g[u].push_back({v, w, cap, signed(g[v].size())});
    g[v].push_back({u, -w, 0, signed(g[u].size() - 1)});
  };
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(s, i, a[i], 0);
    add(i, t, 1, 0);
    add(i, i % n + 1, inf, 1);
    add(i, i - 1 ? i - 1 : n, inf, 1);
  }
  auto spfa = [&]() {
    fill(h.begin(), h.end(), inf);
    h[s] = 0, vis[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      vis[u] = false;
      for (auto &[v, w, cap, id] : g[u]) {
        if (cap && h[v] > h[u] + w) {
          h[v] = h[u] + w;
          if (!vis[v]) {
            vis[v] = true;
            q.push(v);
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

  spfa();
  int maxf = 0, minc = 0;
  while (dijkstra()) {
    for (int i = 0; i <= n + 1; i++) {
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
    minc += minf * h[t]; // h[i] = 1;
  }
  cout << minc << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}