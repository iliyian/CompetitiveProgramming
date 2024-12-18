// date: 2024-03-10 20:40:07
// tag: 网络流配对
// wa#01: 没有特判无解的情况

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

  int k, n;
  cin >> k >> n;
  vector<vector<Edge>> g(k + n + 2);
  auto add = [&](int u, int v, int cap) {
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0, signed(g[u].size() - 1)});
  };
  int s = 0, t = k + n + 1, m = 0;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    add(i + n, t, x);
    m += x;
  }
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    for (int j = 1; j <= p; j++) {
      int x;
      cin >> x;
      add(i, x + n, 1);
    }
    add(s, i, 1);
  }

  vector<int> cur(k + n + 2), d(k + n + 2), dep(k + n + 2);
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
        if (t > 0) {
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
  int res = 0;
  while (bfs()) {
    int r = 0;
    while (r = dfs(dfs, s, inf)) {
      res += r;
    }
  }
  if (res != m) {
    cout << "No Solution!";
    return 0;
  }
  vector<vector<int>> ans(k + 1);
  for (int i = n + 1; i <= k + n; i++) {
    cout << format("{}: ", i - n);
    for (auto &[v, cap, id] : g[i]) {
      if (cap && v != t) {
        cout << v << ' ';
      }
    }
    cout << '\n';
  }

  // cout << ans << '\n';

  return 0;
}