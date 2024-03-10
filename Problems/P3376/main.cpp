// date: 2024-03-10 12:36:09
// tag: ek for max flow

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
using namespace std;

struct Edge {
  int v, cap, id;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<Edge>> g(n + 1);
  vector<int> d(n + 1), pre(n + 1), prp(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].push_back(Edge{v, c, signed(g[v].size())});
    g[v].push_back(Edge{u, 0, signed(g[u].size() - 1)});
  }
  auto bfs = [&]() {
    vector<bool> vis(n + 1);
    queue<int> q;
    d[s] = inf;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int i = 0; i < g[u].size(); i++) {
        auto &[v, cap, id] = g[u][i];
        if (!vis[v] && cap) {
          vis[v] = true;
          d[v] = min(d[u], cap);
          pre[v] = i, prp[v] = u;
          if (v == t) {
            return true;
          }
          q.push(v);
        }
      }
    }
    return false;
  };
  int ans = 0;
  while (bfs()) {
    ans += d[t];
    for (int i = t; i != s; i = prp[i]) {
      auto &e = g[prp[i]][pre[i]];
      e.cap -= d[t];
      g[i][signed(e.id)].cap += d[t];
    }
  }
  cout << ans << '\n';

  return 0;
}