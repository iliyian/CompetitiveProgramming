// date: 2024-03-12 18:00:01
// tag: 费用流
// WA: primal-dual更新势能的时候没有把s和t也就是一般是超级源点和汇点即不属于[1,n]的那两个点的势能也考虑进去

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 105
using namespace std;

struct Edge {
  int v, w, cap, id;
};
vector<vector<Edge>> g;
vector<int> dis, h;
bitset<N> vis;
int s, t;

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

void add(int u, int v, int cap, int w) {
  g[u].push_back({v, w, cap, signed(g[v].size())});
  g[v].push_back({u, -w, 0, signed(g[u].size() - 1)});
}

void spfa() {
  fill(h.begin(), h.end(), inf);
  vis.reset();
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
          vis[v] = true;
          q.push(v);
        }
      }
    }
  }
}

bool dijkstra() {
  fill(dis.begin(), dis.end(), inf);
  priority_queue<Node> q;
  vis.reset();
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

  int n;
  cin >> n;
  g.resize(n + 2);
  dis.resize(n + 2);
  h.resize(n + 2);
  p.resize(n + 2);
  vector<int> a(n + 2);
  s = 0, t = n + 1;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    add(i, i % n + 1, inf, 1);
    add(i, i - 1 ? i - 1 : n, inf, 1);
  }
  int avg = sum / n;
  for (int i = 1; i <= n; i++) {
    if (a[i] > avg) {
      add(i, t, a[i] - avg, 0);
    } else if (a[i] < avg) {
      add(s, i, avg - a[i], 0);
    }
  }

  spfa();
  int maxf = 0, minc = 0;
  while (dijkstra()) {
    int minf = inf;
    for (int i = 0; i <= n + 1; i++) {
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