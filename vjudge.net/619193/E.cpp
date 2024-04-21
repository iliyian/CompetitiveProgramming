#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 10005
using namespace std;

struct Edge {
  int v, w, cap, id;
};
vector<vector<Edge>> g;
vector<int> dis, h;
bitset<N> vis;
int n, m, s, t, minc = 0, S, T;

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
  q.push(S);
  vis[S] = true;
  fill(h.begin(), h.end(), inf);
  h[S] = 0;
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
  q.push({S, dis[S] = 0});
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
  return dis[T] != inf;
}

void add(int u, int v, int w, int cap) {
  g[u].push_back({v, w, cap, signed(g[v].size())});
  g[v].push_back({u, -w, 0, signed(g[u].size() - 1)});
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  
  cin >> m >> n;
  s = 0, t = n * 2 + 1;
  S = t + 1, T = t + 2;
  g.resize(T + 1);
  dis.resize(T + 1);
  h.resize(T + 1);
  p.resize(T + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    add(i, i + n, -x, 1);
    add(s, i, 0, 1);
    add(i + n, t, 0, 1);
  }
  add(S, s, 0, 1);
  add(t, T, 0, 1);
  vector<vector<int>> a(m + 1, vector<int>(n + 1));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      bool f1 = true, f2 = true;
      for (int k = 1; k <= m; k++) {
        if (a[k][i] >= a[k][j]) {
          f1 = false;
        }
        if (a[k][i] <= a[k][j]) {
          f2 = false;
        }
      }
      if (f1) {
        add(i + n, j, 0, 1);
      }
      if (f2) {
        add(j + n, i, 0, 1);
      }
    }
  }
  spfa();
  int maxf = 0;
  while (dijkstra()) {
    int minf = inf;
    for (int i = 0; i <= n * 2 + 3; i++) {
      h[i] += dis[i];
    }
    for (int i = T; i != S; i = p[i].p) {
      minf = min(minf, g[p[i].p][p[i].e].cap);
    }
    for (int i = T; i != S; i = p[i].p) {
      auto &e = g[p[i].p][p[i].e];
      e.cap -= minf;
      g[i][e.id].cap += minf;
    }
    maxf += minf;
    minc += minf * h[T];
  }
  // cout << maxf << '\n';
  cout << -minc << '\n';

  return 0;
}