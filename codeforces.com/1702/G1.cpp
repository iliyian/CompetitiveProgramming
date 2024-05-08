#include <bits/stdc++.h>
#define int long long
#define N 200000
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  bitset<N + 5> vis, grand;

  vector<vector<int>> pa(n + 1, vector<int>(21));
  vector<int> dep(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    pa[u][0] = p;
    for (int i = 1; i <= 20; i++) {
      pa[u][i] = pa[pa[u][i - 1]][i - 1];
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);

  auto lca = [&](int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 20; i >= 0; i--) {
      if (dep[y] <= dep[x] - (1 << i)) {
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

  int q;
  cin >> q;
  for (int _ = 1; _ <= q; _++) {
    int k;
    cin >> k;
    vis.reset();
    grand.reset();
    int r = 0, l = 0;
    for (int i = 1; i <= k; i++) {
      int x;
      cin >> x;
      if (dep[x] > dep[r]) r = x;
      vis[x] = true;
    }

    int t = r;
    while (t) {
      grand[t] = true;
      t = pa[t][0];
    }

    for (int i = 1; i <= n; i++) {
      if (vis[i] && !grand[i] && dep[i] > dep[l]) {
        l = i;
      }
    }

    int lc = lca(l, r);

    int cnt = vis[lc];
    while (l != lc) {
      cnt += vis[l];
      l = pa[l][0];
    }

    while (r != lc) {
      cnt += vis[r];
      r = pa[r][0];
    }

    cout << (cnt == k ? "YES" : "NO") << '\n';
  }

  return 0;
}