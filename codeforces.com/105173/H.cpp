#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<pair<int, int>> a;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  vector<int> dep(n + 1);
  vector<vector<int>> pa(n + 1, vector<int>(21));
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

  vector<int> lc(m + 1), dis(m + 1);
  for (int i = 1; i <= m; i++) {
    lc[i] = lca(a[i].first, a[i].second);
    dis[i] = dep[a[i].first] - dep[lc[i]] + dep[a[i].second] - dep[lc[i]];
  }

  auto check = [&](int mid) {
    for (int i = 1; i <= m; i++) {
      if (dis[i] <= mid) continue;
      auto &[x, y] = a[i];
      if (dep[x] - dep[lc[i]] <= mid) {
        
      } else {

      }
      
      if (dep[y] - dep[lc[i]] <= mid) {

      } else {

      }
    }

  };

  int l = 0, r = n - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans << '\n';

  return 0;
}