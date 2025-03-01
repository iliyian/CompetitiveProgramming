// date: 2024-03-10 22:14:43
// tag: 最小割点，
// re#01: g初始化在输入n之前，s的出点而非入点为真正的s

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

  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<Edge>> g(n * 2 + 1);
  auto add = [&](int u, int v, int cap) {
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0, signed(g[u].size() - 1)});
  };
  for (int i = 1; i <= n; i++) {
    add(i, i + n, 1);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    add(u + n, v, inf);
    add(v + n, u, inf);
  }

  vector<int> cur(n * 2 + 1), d(n * 2 + 1), dep(n * 2 + 1);
  auto bfs = [&]() {
    fill(cur.begin(), cur.end(), 0);
    fill(dep.begin(), dep.end(), 0);
    queue<int> q;
    q.push(s);
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

  int res = 0;
  while (bfs()) {
    int r = 0;
    while (r = dfs(dfs, s + n, inf)) {
      res += r;
    }
  }
  cout << res << '\n';

  return 0;
}