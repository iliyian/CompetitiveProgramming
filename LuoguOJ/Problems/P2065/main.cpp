// date: 2024-03-12 12:10:38
// tag: 最大流

#include <bits/stdc++.h>
#define int long long
#define N 10000005
using namespace std;

bitset<N> vis;
vector<int> pri;

struct Edge {
  int v, cap, id;
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> r(n + 1), b(m + 1);
  int s = 0, t = 0;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
    t = max(t, r[i]);
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    t = max(t, b[i]);
  }
  t++;
  vector<vector<Edge>> g(t + 1);
  auto add = [&](int u, int v, int cap) {
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0, signed(g[u].size() - 1)});
  };
  for (int i = 1; i <= n; i++) {
    add(s, r[i], 1);
    for (int p : pri) {
      if (p > r[i]) break;
      if (r[i] % p == 0) {
        add(r[i], p, 1);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    add(b[i], t, 1);
    for (int p : pri) {
      if (p > b[i]) break;
      if (b[i] % p == 0) {
        add(p, b[i], 1);
      }
    }
  }
  vector<int> cur(t + 1), dep(t + 1), d(t + 1);
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
  int ans = 0;
  while (bfs()) {
    int r = 0;
    while (r = dfs(dfs, s, INT_MAX)) {
      ans += r;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  for (int i = 2; i < N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p >= N) break;
      vis[i * p] = true;
      if (i % p == 0) {
        break;
      }
    }
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}