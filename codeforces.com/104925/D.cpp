#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Edge {
  int v, cap, id;
};

void solve() {
  int n, m;
  cin >> n >> m;
  int s = 0, t = n * 2 + 1;
  vector<int> a(m + 1);
  vector<vector<Edge>> g(t + 1);
  auto add = [&](int u, int v, int cap) {
    g[u].push_back({v, cap, signed(g[v].size())});
    g[v].push_back({u, 0, signed(g[u].size() - 1)});
  };
  vector<bool> isf(n + 1), vis(n + 1);
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    isf[a[i]] = true;
  }
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= m; i++) {
    add(a[i], a[i] + n, 1);
    if (a[i - 1] != a[i] - 1) {
      add(s, a[i], 1);
    } else {
      add(a[i - 1], a[i], 1);
    }
  }
  vector<int> x(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    if (isf[x[i]]) {
      if (!isf[x[i - 1]]) {
        add(x[i] + n, t, 1);
      } else {
        add(x[i - 1] + n, x[i] + n, 1);
      }
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

  int mincut = 0;
  while (bfs()) {
    int r = 0;
    while (r = dfs(dfs, s, inf)) {
      mincut += r;
    }
  }
  cout << mincut << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}