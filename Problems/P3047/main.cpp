// date: 2024-03-24 13:40:03
// tag: 树形dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  vector<vector<int>> f(n + 1, vector<int>(21)), d(n + 1, vector<int>(21));
  auto dfs1 = [&](auto self, int u, int p) -> void {
    f[u][0] = c[u];
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        for (int i = 1; i <= k; i++) {
          f[u][i] += f[v][i - 1];
        }
      }
    }
  };
  dfs1(dfs1, 1, 0);
  copy(f.begin(), f.end(), d.begin());

  auto dfs2 = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        for (int i = 1; i <= k; i++) {
          d[v][i] += d[u][i - 1] - (i >= 2 ? f[v][i - 2] : 0);
        }
        self(self, v, u);
      }
    }
  };
  dfs2(dfs2, 1, 0);
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 0; j <= k; j++) {
      ans += d[i][j];
    }
    cout << ans << '\n';
  }

  return 0;
}