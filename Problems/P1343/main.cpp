// date: 2024-04-04 13:25:24
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

  int n, m, x;
  cin >> n >> m >> x;
  int s = 1, t = n;
  vector<vector<Edge>> g(n + 1);
  auto add = [&](int u, int v, int cap) {
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0, signed(g[u].size() - 1)});
  };
  for (int i = 1; i <= m; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    add(u, v, x);
    // add(v, u, x);
  }
  vector<int> dep(n + 1), cur(n + 1);
  auto bfs = [&](auto s) -> bool {
    queue<int> q;
    q.push(s);
    fill(cur.begin(), cur.end(), 0);
    fill(dep.begin(), dep.end(), 0);
    dep[s] = 1;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto &[v, cap, id] : g[u]) {
        if (cap && !dep[v]) {
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
      if (cap && dep[v] == dep[u] + 1) {
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
  while (bfs(s)) {
    int r = 0;
    while (r = dfs(dfs, s, inf)) {
      ans += r;
    }
  }
  if (ans == 0) {
    cout << "Orz Ni Jinan Saint Cow!";
    return 0;
  }
  cout << format("{} {}", ans, (x - 1) / ans + 1);

  return 0;
}