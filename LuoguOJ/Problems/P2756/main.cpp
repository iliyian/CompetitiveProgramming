// date: 2024-03-10 13:49:07
// tag: tle#01: 死循环,cur数组没有赋0

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

  int m, n;
  cin >> m >> n;
  int u, v;
  vector<vector<Edge>> g(n + 2);
  vector<int> dep(n + 2), cur(n + 2), d(n + 2);
  int s = 0, t = n + 1;
  auto addedge = [&](int u, int v, int cap) {
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0, signed(g[u].size() - 1)});
  };
  for (int i = 1; i <= n; i++) {
    if (i <= m) {
      addedge(s, i, 1);
    } else {
      addedge(i, t, 1);
    }
  }
  while (cin >> u >> v && (u != -1 && v != -1)) {
    addedge(u, v, 1);
  }
  auto bfs = [&]() {
    queue<int> q;
    fill(dep.begin(), dep.end(), -1);
    fill(cur.begin(), cur.end(), 0);
    dep[s] = 1;
    q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto &[v, cap, id] : g[u]) {
        if (dep[v] == -1 && cap) {
          dep[v] = dep[u] + 1;
          q.push(v);
        }
      }
    }
    return dep[t] != -1;
  };
  auto dfs = [&](auto self, int u, int lim) -> int {
    if (u == t) {
      return lim;
    }
    for (int i = cur[u]; i < g[u].size(); i++) {
      auto &[v, cap, id] = g[u][i];
      cur[u] = i;
      if (dep[v] == dep[u] + 1 && cap) {
        int t = self(self, v, min(lim, cap));
        if (t) {
          cap -= t;
          g[v][id].cap += t;
          return t;
        } else {
          dep[v] = -1;
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
  // int cnt = 0;
  vector<pair<int, int>> vec;
  for (int u = 1; u <= m; u++) {
    for (auto &[v, cap, id] : g[u]) {
      if (v != n + 1 && v && g[v][id].cap) {
        // cnt++;
        vec.push_back({u, v});
      }
    }
  }
  // cout << cnt << '\n';
  for (auto [x, y] : vec) {
    cout << x << ' ' << y << '\n';
  }

  return 0;
}