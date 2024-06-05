// date: 2024-06-02 21:29:18
// tag: 模拟，暴力

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  set<int> s;
  auto dfs = [&](auto self, int u, int p, int x) -> void {
    s.insert(x);
    for (auto [v, w] : g[u]) {
      if (v != p) {
        if (v == b && (w ^ x) == 0 || v != b) {
          self(self, v, u, x ^ w);
        }
      }
    }
  };
  dfs(dfs, a, 0, 0);

  bool f = false;
  auto dfs2 = [&](auto self, int u, int p, int x) -> void {
    if (f) return;
    if (u != b && s.count(x)) {
      cout << "YES\n";
      f = true;
      return;
    }
    for (auto [v, w] : g[u]) {
      if (v != p) {
        self(self, v, u, x ^ w);
      }
    }
  };
  dfs2(dfs2, b, 0, 0);
  if (!f) {
    cout << "NO\n";
  }
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