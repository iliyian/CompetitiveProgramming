// date: 2024-04-10 19:50:48
// tag: 费用流
// 关键在于，源点一定要连向汇点，源点绝不能流向源点
// 不知道s和t怎么整不妨先把中间的部分建好再说？

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

  int N;
  cin >> N;
  int s = 0, t = N * 2 + 1;
  vector<vector<Edge>> g(t + 1);
  vector<int> a(N + 1);
  auto add = [&](int u, int v, int w, int cap) {
    g[u].push_back({v, w, cap, signed(g[v].size())});
    g[v].push_back({u, -w, 0, signed(g[u].size() - 1)});
  };
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    if (i != N) add(i + N, i + 1 + N, 0, inf);
    add(s, i + N, 0, a[i]);
    add(i, t, 0, a[i]);
  }
  int p0, m, f, n, s0;
  cin >> p0 >> m >> f >> n >> s0;
  for (int i = 1; i <= N; i++) {
    add(s, i, p0, inf);
    if (i + m <= N) add(i + N, i + m, f, inf);
    if (i + n <= N) add(i + N, i + n, s0, inf);
  }

  vector<int> h(t + 1);
  bitset<4005> vis;
  auto spfa = [&]() {
    queue<int> q;
    q.push(s);
    fill(h.begin(), h.end(), 0);
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
    vis.reset();
    fill(dis.begin(), dis.end(), inf);
    priority_queue<Node> q;
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
    minc += minf * h[t];
    maxf += minf;
  }
  cout << minc << '\n';

  return 0;
}