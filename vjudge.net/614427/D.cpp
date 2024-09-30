#include <bits/stdc++.h>
// #define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> lv(n + 1), rv(n + 1);
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> lv[i] >> rv[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  vector<pair<int, int>> vis(n + 1);
  auto dfs = [&](auto self, int u, int l, int r) {
    if (vis[u] != pair{0, 0}
      && vis[u].first <= l && vis[u].second >= r) return;
    vis[u] = {l, r};
    for (int v : adj[u]) {
      if (r >= lv[v] && l <= rv[v]) {
        self(self, v, max(l, lv[v]), min(r, rv[v]));
      }
    }
  };
  dfs(dfs, 1, lv[1], rv[1]);
  for (int i = 1; i <= n; i++) {
    if (vis[i] != pair{0, 0}) {
      cout << i << ' ';
    }
  }

  return 0;
}