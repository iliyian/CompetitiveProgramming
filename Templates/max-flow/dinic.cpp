// date: 2024-03-11 12:55:09
// tag: 网络流

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Edge {
  int v, cap, id;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n + 2);
  auto add = [&](int u, int v, int cap) {
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0, signed(g[u].size() - 1)});
  };
  int s = 0, t = n + 1;
  vector<int> dep(n + 2), cur(n + 2);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x) {
      add(s, i, 1);
    } else {
      add(i, t, 1);
    }
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v, 1);
    add(v, u, 1);
  }
  auto bfs = [&]() {
    queue<int> q;
    q.push(s);
    fill(dep.begin(), dep.end(), 0);
    fill(cur.begin(), cur.end(), 0);
    dep[s] = 1;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto &[v, cap, id] : g[u]) {
        if (!dep[v] && cap) {
          dep[v] = dep[u] + 1;
          q.push(v);
        }
      }
    }
    return dep[t];
  };
  auto dfs = [&](auto self, int u, int lim) -> int {
    if (u == t) {
      return lim;
    }
    for (int i = cur[u]; i < g[u].size(); i++) {
      cur[u] = i;
      auto &[v, cap, id] = g[u][i];
      if (dep[v] == dep[u] + 1 && cap) {
        int t = self(self, v, min(lim, cap));
        if (t) {
          cap -= t;
          g[v][id].cap += t;
          return t;
        } else {
          dep[v] = 0;
        }
      }
    }
    return 0;
  };
  int ans = 0;
  while (bfs()) {
    int r = 0;
    while (r = dfs(dfs, s, inf)) {
      ans += r;
    }
  }
  cout << ans << '\n';

  return 0;
}