// date: 2024-05-05 23:47:26
// tag: 树上dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 0;
  vector<int> siz(n + 1), nxt(n + 1), f(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    if (g[u].size() == 1 && u != 1) {
      f[u] = 0;
      return;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
        if (siz[v] - 1 - f[v] > siz[nxt[u]] - 1 - f[nxt[u]]) {
          nxt[u] = v;
        }
      }
    }
    for (int v : g[u]) {
      if (v != nxt[u]) {
        f[u] += f[v];
      }
    }
    f[u] += siz[nxt[u]] - 1;
  };
  dfs(dfs, 1, 0);
  cout << f[1] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}