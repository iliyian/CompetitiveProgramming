// date: 2024-05-17 20:09:48
// tag: 树形dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }

  vector<array<int, 2>> f(n + 1, array<int, 2>{});
  auto dfs = [&](auto self, int u) -> void {
    f[u][1] = 1;
    for (int v : g[u]) {
      self(self, v);
      f[u][1] = max(f[u][1], f[v][1] + 1);
      f[u][0] += max(f[v][0], f[v][1]);
    }
  };
  dfs(dfs, 1);
  cout << max(f[1][1], f[1][0]) << '\n';

  return 0;
}