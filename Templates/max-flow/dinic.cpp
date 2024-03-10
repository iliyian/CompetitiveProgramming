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
  vector<int> dep(n + 1, -1), cur(n + 1), d(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].push_back(Edge{v, c, signed(g[v].size())});
    g[v].push_back(Edge{u, 0, signed(g[u].size() - 1)});
  }
  int ans = 0;
  auto bfs = [&]() {
    queue<int> q;
    fill(dep.begin() + 1, dep.end(), -1);
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
        int t = self(self, v, min(cap, lim));
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
  while (bfs()) {
    int r = 0;
    fill(cur.begin() + 1, cur.end(), 0);
    // 切记啊切记啊
    while (r = dfs(dfs, s, inf)) {
      ans += r;
    }
  }
  cout << ans << '\n';

  return 0;
}