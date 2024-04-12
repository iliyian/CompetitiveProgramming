// date: 2024-04-11 15:56:52
// tag: 已经不知道多少次minf没有初始化为inf了

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;

struct Edge {
  int v, cap, id;
  double w;
};

struct Node {
  int u;
  double d;
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
  vector<int> xs(n + 1), ys(n + 1);
  int s = 0, t = n * 2 + 1;
  vector<vector<Edge>> g(t + 1);
  auto add = [&](int u, int v, double w, int cap) {
    g[u].push_back({v, cap, signed(g[v].size()), w});
    g[v].push_back({u, 0, signed(g[u].size() - 1), -w});
  };
  auto di = [&](int i, int j) -> double {
    return sqrt((xs[i] - xs[j]) * (xs[i] - xs[j]) + (ys[i] - ys[j]) * (ys[i] - ys[j]));
  };
  for (int i = 1; i <= n; i++) {
    cin >> xs[i] >> ys[i];
    add(s, i + n, 0, 2);
    add(i, t, 0, 1);
    for (int j = 1; j < i; j++) {
      if (ys[j] < ys[i]) {
        add(i + n, j, di(i, j), 1);
      } else if (ys[j] > ys[i]) {
        add(j + n, i, di(i, j), 1);
      }
    }
  }

  vector<double> h(t + 1);
  bitset<1000> vis;
  auto spfa = [&]() {
    fill(h.begin(), h.end(), inf);
    queue<int> q;
    q.push(s);
    vis[s] = true, h[s] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      vis[u] = false;
      for (auto &[v, cap, id, w] : g[u]) {
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

  vector<double> dis(t + 1);
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
        auto &[v, cap, id, w] = g[u][i];
        double ww = w + h[u] - h[v];
        if (cap && dis[v] > dis[u] + ww) {
          dis[v] = dis[u] + ww;
          p[v] = {u, i};
          q.push({v, dis[v]});
        }
      }
    }
    return dis[t] != inf;
  };

  double minc = 0;
  int maxf = 0;
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
  if (maxf != n - 1) {
    cout << -1 << '\n';
  } else {
    cout << fixed << setprecision(20) << minc << '\n';
  }

  return 0;
}