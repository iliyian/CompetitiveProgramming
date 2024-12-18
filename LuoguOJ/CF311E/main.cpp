// date: 2024-04-10 21:19:12
// tag: 最大权闭合子图

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 13000
using namespace std;

struct Edge {
  int v, cap, id;
};

struct Node {
  int u, d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

struct Pre {
  int p, e;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m, g0;
  cin >> n >> m >> g0;
  vector<int> a(n + 1), v(n + 1);
  int s = 0, t = n + m + 1;
  vector<vector<Edge>> g(t + 1);
  auto add = [&](int u, int v, int cap) {
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0, signed(g[u].size() - 1)});
  };
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    if (a[i]) add(i, t, v[i]);
    else add(s, i, v[i]);
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int r, w, k, f;
    cin >> r >> w >> k;
    ans += w;
    for (int j = 1; j <= k; j++) {
      int x;
      cin >> x;
      if (r) add(x, n + i, inf);
      else add(n + i, x, inf);
    }
    cin >> f;
    w += g0 * f;
    if (r) add(n + i, t, w);
    else add(s, n + i, w);
  }
  vector<int> dep(t + 1), cur(t + 1);
  bitset<N> vis;

  auto bfs = [&]() {
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
        int t = self(self, v, min(cap, lim));
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
  while (bfs()) {
    int r = 0;
    while (r = dfs(dfs, s, inf)) {
      ans -= r;
    }
  }
  
  cout << ans << '\n';

  return 0;
}