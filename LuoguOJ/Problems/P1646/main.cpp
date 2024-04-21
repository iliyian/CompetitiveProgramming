// date: 2024-04-10 18:11:03
// tag: 最大权闭合子图

#include <bits/stdc++.h>
#define int long long
#define N 100005
#define inf 0x3f3f3f3f3f3f3f3f
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

bitset<N> vis;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  int s = 0, t = 6 * m * n - 2 * m - 2 * n + 1, ans = 0;
  vector<vector<Edge>> g(t + 1);
  vector<Pre> p(t + 1);

  auto add = [&](int u, int v, int cap) {
    if (cap != inf) ans += cap;
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0,  signed(g[u].size() - 1)});
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      add(s, i * n + j, x);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      add(i * n + j, t, x);
    }
  }

  int cnt = n * m * 2;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= m; j++) {
      int x = i * n + j, y = (i + 1) * n + j, c, z = ++cnt;
      cin >> c;
      add(s, z, c);
      add(z, x, inf);
      add(z, y, inf);
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= m; j++) {
      int x = i * n + j, y = (i + 1) * n + j, c, z = ++cnt;
      cin >> c;
      add(z, t, c);
      add(x, z, inf);
      add(y, z, inf);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m - 1; j++) {
      int x = i * n + j, y = i * n + j + 1, c, z = ++cnt;
      cin >> c;
      add(s, z, c);
      add(z, x, inf);
      add(z, y, inf);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m - 1; j++) {
      int x = i * n + j, y = i * n + j + 1, c, z = ++cnt;
      cin >> c;
      add(z, t, c);
      add(x, z, inf);
      add(y, z, inf);
    }
  }

  vector<int> dep(t + 1), cur(t + 1);
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
  cout << ans - maxf << '\n';
  cerr << ans << ' ' << maxf << '\n';

  return 0;
}