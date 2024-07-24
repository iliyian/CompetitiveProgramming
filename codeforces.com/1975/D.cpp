#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b, n;
  cin >> n >> a >> b;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<vector<int>> pa(n + 1, vector<int>(21));
  vector<int> dep(n + 1), siz(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    pa[u][0] = p;
    dep[u] = dep[p] + 1;
    siz[u] = 1;
    for (int i = 1; i <= n; i++) {
      pa[u][i] = pa[pa[u][i - 1]][i - 1];
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
  };
  dfs(dfs, 1, 0);
  auto lca = [&](int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 20; i >= 0; i--) {
      if (dep[x] - (1 << i) >= dep[y]) {
        x = pa[x][i];
      }
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
      if (pa[x][i] != pa[y][i]) {
        x = pa[x][i], y = pa[y][i];
      }
    }
    return pa[x][0];
  };
  int dis = dep[a] - 1 + dep[b] - 1;
  int lc = 0;
  if (dis % 2 == 0) {
    dis /= 2;
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 20; i >= 0; i--) {
      if (dis & 1 >> i) {
        a = pa[a][i];
      }
    }
    int maxsz = 0;
    for (int v : g[a]) {
      int sz = siz[v] - 1;
      if (v == pa[a][0]) {
        sz = n - siz[a];
      }
      maxsz = max(maxsz, sz);
    }
    int ans = dis + 
  }
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