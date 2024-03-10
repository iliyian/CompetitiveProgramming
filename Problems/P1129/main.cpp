// date: 2024-03-10 14:46:15
// tag: 最大流

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
  int v, cap, id;
};

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  vector<vector<Edge>> g(n * 2 + 2);
  vector<int> dep(n * 2 + 2), cur(n * 2 + 2), d(n * 2 + 2);

  auto add = [&](int u, int v, int cap) {
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0, signed(g[u].size() - 1)});
  };

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j]) {
        add(i, j + n, 1);
      }
    }
  }
  int s = 0, t = n * 2 + 1;
  for (int i = 1; i <= n; i++) {
    add(s, i, 1);
    add(i + n, t, 1);
  }
  auto bfs = [&]() {
    queue<int> q;
    fill(cur.begin(), cur.end(), 0);
    fill(dep.begin(), dep.end(), 0);
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
  int ans = 0;
  while (bfs()) {
    int r = 0;
    while (r = dfs(dfs, s, 0x3f3f3f3f)) {
      ans += r;
    }
  }
  // maximum as well
  cout << (ans == n ? "Yes" : "No") << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}