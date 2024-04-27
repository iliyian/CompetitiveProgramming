// date: 2024-04-26 21:33:06
// tag: 图上dp

#include <bits/stdc++.h>
#define int long long
#define N 200000
#define mod 1000000007
using namespace std;

void solve() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<int>> g(n + 1);
  vector<pair<int, int>> edges;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.push_back({u, v});
  }
  vector<int> ds(n + 1, -1), dt(n + 1, -1), cs(n + 1), ct(n + 1);

  auto bfs = [&g](int s, vector<int> &d, vector<int> &c) {
    queue<int> q;
    q.push(s);
    d[s] = 0;
    c[s] = 1;
    while (!q.empty()) {
      auto u = q.front(); q.pop();
      for (int v : g[u]) {
        if (d[v] == -1) {
          q.push(v);
          d[v] = d[u] + 1;
          c[v] = c[u];
        } else if (d[v] == d[u] + 1) {
          c[v] = (c[v] + c[u]) % mod;
        }
      }
    }
  };

  bfs(s, ds, cs);
  bfs(t, dt, ct);

  int ans = cs[t];

  for (auto [u, v] : edges) {
    if (ds[u] == ds[v]) {
      if (ds[u] + dt[v] == ds[t]) {
        ans += cs[u] * ct[v] % mod;
        ans %= mod;
      }
      if (dt[u] + ds[v] == ds[t]) {
        ans += ct[u] * cs[v] % mod;
        ans %= mod;
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}