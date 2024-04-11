// date: 2024-04-11 13:21:44
// tag: 拆出的两点间不应该相连

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

  int n, m;
  cin >> n >> m;
  int s = 0, t = n * 2 + 2;
  vector<vector<Edge>> g(t + 1);
  auto add = [&](int u, int v, int w, int cap) {
    g[u].push_back({v, w, cap, signed(g[v].size())});
    g[v].push_back({u, -w, 0, signed(g[u].size() - 1)});
  };
  add(s, t - 1, 0, m);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    add(s, i + n, 0, x);
    add(i, t, 0, x);
    add(t - 1, i, 0, x);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= n - i; j++) {
      int x;
      cin >> x;
      if (x == -1) continue;
      add(i + n, i + j, x, inf);
    }
  }

  vector<int> h(t + 1);
  bitset<205> vis;
  auto spfa = [&]() {
    queue<int> q;
    q.push(s);
    vis[s] = true, h[s] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      vis[u] = false;
      for (auto &[v, w, cap, id] : g[u]) {
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
  vector<Pre> p(t + 1);
  auto dijkstra = [&]() {
    priority_queue<Node> q;
    vis.reset();
    fill(dis.begin(), dis.end(), inf);
    q.push({s, dis[s] = 0});
    while (!q.empty()) {
      int u = q.top().u; q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (int i = 0; i < g[u].size(); i++) {
        auto &[v, w, cap, id] = g[u][i];
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
    minc += minf * h[t];
  }
  cout << minc << '\n';
  cerr << maxf << '\n';

  return 0;
}