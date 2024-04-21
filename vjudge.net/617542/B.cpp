#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Edge {
  int v, c;
};

struct Node {
  int u, d, maxw, p;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

void solve() {
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> w(n + 1);
  vector<vector<Edge>> g(n + 1);
  vector<int> dis(n + 1, inf);
  vector<bool> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    g[u].push_back({v, c});
  }
  map<tuple<int, int, int>, bool> mem;

  int ans = inf;
  auto dfs = [&](auto self, int u, int maxw, int curp, int curd) {
    if (u == n) {
      ans = min(ans, curd);
      return;
    }
    if (vis[u]) return;
    vis[u] = true;
    if (mem[tuple{u, maxw, curd}]) {
      return;
    }
    mem[tuple{u, maxw, curd}] = true;
    for (auto &[v, c] : g[u]) {
      int nd;
      if (curp >= c) nd = 0;
      else nd = (c - curp - 1) / maxw + 1;
      self(self, v, max(maxw, w[v]), curp + nd * maxw - c, curd + nd);
      vis[v] = false;
    }
  };
  dfs(dfs, 1, w[1], p, 0);
  cout << (ans == inf ? -1 : ans) << '\n';
  // cout << -1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}