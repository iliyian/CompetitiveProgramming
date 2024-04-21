// date: 2024-04-11 14:25:04
// tag: 最大权闭合子图

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

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
  int s = 0, t = n * m * 3 + 1;
  vector<vector<Edge>> g(t + 1);
  int ans = 0;
  auto add = [&](int u, int v, int cap) {
    if (cap != inf) ans += cap;
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0, signed(g[u].size() - 1)});
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      add(s, (i - 1) * m + j, x);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      add((i - 1) * m + j, t, x);
    }
  }
  int cnt = n * m;
  auto in = [&n, &m](int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int c;
      cin >> c;
      int x = (i - 1) * m + j, y = ++cnt;
      add(s, y, c);
      add(y, x, inf);
      for (int d = 0; d < 4; d++) {
        int ii = i + dx[d], jj = j + dy[d];
        if (in(ii, jj)) {
          add(y, (ii - 1) * m + jj, inf);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int c;
      cin >> c;
      int x = (i - 1) * m + j, y = ++cnt;
      add(y, t, c);
      add(x, y, inf);
      for (int d = 0; d < 4; d++) {
        int ii = i + dx[d], jj = j + dy[d];
        if (in(ii, jj)) {
          add((ii - 1) * m + jj, y, inf);
        }
      }
    }
  }

  vector<int> dep(t + 1), cur(t + 1);
  auto bfs = [&]() {
    fill(dep.begin(), dep.end(), 0);
    fill(cur.begin(), cur.end(), 0);
    queue<int> q;
    q.push(s);
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
  assert(cnt == t - 1);
  cerr << cnt << '\n' << maxf << '\n';

  // for (auto &[v, cap, id] : g[s]) {
  //   if (v <= n * m) {
  //     cout << format("{} {}: {}\n", (v - 1) / m + 1, v % m ? v % m : m, cap);
  //   }
  // }
  // for (auto &[v, cap, id] : g[t]) {
  //   if (v <= n * m) {
  //     cout << format("{} {}: {}\n", (v - 1) / m + 1, v % m ? v % m : m, cap);
  //   }
  // }

  return 0;
}