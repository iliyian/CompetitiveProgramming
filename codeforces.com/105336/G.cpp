// date: 2024-09-09 19:16:21
// tag: 网络流

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
  int v, cap, id;
};

signed main() {
  freopen("G.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n + 1), v(n + 1), x(m + 1), y(m + 1), w(m + 1), mx(n + 1), wsum(n + 1);
  int s = 0, t = m + n + 1;

  std::vector<std::vector<Edge>> g(t + 1);
  std::vector<int> dep(t + 1), cur(t + 1);

  auto add = [&](int u, int v, int cap) -> void {
    g[u].push_back({v, cap, (signed)g[v].size()});
    g[v].push_back({u, 0, (signed)g[u].size() - 1});
  };

  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> v[i];
  }

  int sum = 0;
  for (int i = 1; i <= m; i++) {
    std::cin >> x[i] >> y[i] >> w[i];
    wsum[x[i]] += w[i];
    sum += w[i];
    if (x[i] != y[i]) {
      wsum[y[i]] += w[i];
    }
  }

  mx[1] = std::min(wsum[1] + v[1], a[1]);
  for (int i = 2; i <= n; i++) {
    mx[i] = std::min({mx[1] - 1, wsum[i] + v[i], a[i]});
  }

  for (int i = 1; i <= m; i++) {
    add(s, i, w[i]);
    add(i, x[i] + m, w[i]);
    if (x[i] != y[i]) {
      add(i, y[i] + m, w[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (mx[i] < v[i]) {
      std::cout << "NO\n";
      return 0;
    }
    add(m + i, t, mx[i] - v[i]);
  }

  auto bfs = [&]() {
    std::queue<int> q;
    q.push(s);
    std::fill(dep.begin(), dep.end(), 0);
    std::fill(cur.begin(), cur.end(), 0);
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
        int t = self(self, v, std::min(lim, cap));
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
    int f = 0;
    while (f = dfs(dfs, s, INT_MAX), f) {
      maxf += f;
    }
  }

  std::cout << (sum == maxf ? "YES" : "NO") << '\n';

  return 0;
}