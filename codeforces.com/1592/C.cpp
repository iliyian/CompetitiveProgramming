// date: 2024-04-13 15:31:05
// tag: 树，位运算，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  int m = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    m ^= a[i];
  }
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (m == 0) {
    cout << "YES\n";
    return;
  }
  if (m && k == 2) {
    cout << "NO\n";
    return;
  }
  bool f = false;
  vector<int> cnt(n + 1);
  auto dfs = [&](auto self, int u, int p) -> int {
    int x = a[u];
    for (int v : g[u]) {
      if (v != p) {
        int t = self(self, v, u);
        cnt[u] += !!(cnt[v] || t == m);
        x ^= t;
      }
    }
    if (cnt[u] && x == 0 || cnt[u] >= 2) f = true;
    return x;
  };
  dfs(dfs, 1, 0);
  cout << (f ? "YES" : "NO") << '\n';
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