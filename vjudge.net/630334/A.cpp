#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  vector<array<int, 2>> f(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        f[p][1] += f[v][1];
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);

  return 0;
}