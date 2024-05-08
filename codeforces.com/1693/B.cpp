// date: 2024-05-07 11:17:36
// tag: 树形dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> l(n + 1), r(n + 1);
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  vector<int> a(n + 1);
  int ans = 0;
  auto dfs = [&](auto self, int u, int p) {
    if (g[u].empty()) {
      a[u] = r[u];
      ans++;
      return;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        a[u] += a[v];
      }
    }
    if (a[u] < l[u]) ans++, a[u] = r[u];
    else a[u] = min(r[u], a[u]);
  };
  dfs(dfs, 1, 0);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}