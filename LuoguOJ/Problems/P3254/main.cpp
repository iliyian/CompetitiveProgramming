// date: 2024-04-05 17:35:58
// tag: 最大流匹配

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
  int s = 0, t = n + m + 1;
  vector<int> a(t + 1), b(t + 1);
  vector<vector<Edge>> g(t + 1);
  auto add = [&](int x, int y, int cap) {
    g[x].push_back({y, cap, signed(g[y].size())});
    g[y].push_back({x, 0, signed(g[x].size() - 1)});
  };
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(s, i, a[i]);
    sum += a[i];
    for (int j = n + 1; j <= n + m; j++) {
      add(i, j, 1);
    }
  }
  for (int i = n + 1; i <= m + n; i++) {
    cin >> b[i];
    add(i, t, b[i]);
  }
  vector<int> dep(t + 1), cur(t + 1);
  auto bfs = [&]() -> bool {
    queue<int> q;
    q.push(s);
    fill(dep.begin(), dep.end(), 0);
    fill(cur.begin(), cur.end(), 0);
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
  int maxf = 0;
  while (bfs()) {
    int r = 0;
    while (r = dfs(dfs, s, inf)) {
      maxf += r;
    }
  }
  if (sum != maxf) {
    cout << 0 << '\n';
    return 0;
  }
  cout << 1 << '\n';
  for (int u = 1; u <= n; u++) {
    for (auto &[v, cap, id] : g[u]) {
      if (v != s && !cap) {
        cout << v - n << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}