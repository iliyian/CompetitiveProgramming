// date: 2024-06-11 20:27:30
// tag: 树形dp

#include <bits/stdc++.h>
#define int long long
#define N ((int)2e5)
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, d;
  cin >> n >> d;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 4 * (n - 1);
  vector<int> dep(n + 1);
  array<bitset<N + 1>, 2> req;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    req[0][x] = true;
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    req[1][x] = true;
  }

  auto dfs = [&](auto self, int u, int p) -> pair<int, int> {
    dep[u] = dep[p] + 1;
    int mxx = 0, mxy = 0;
    if (req[0][u]) {
      mxx = dep[u];
    }
    if (req[1][u]) {
      mxy = dep[u];
    }
    for (int v : g[u]) {
      if (v != p) {
        auto [x, y] = self(self, v, u);
        mxx = max(x, mxx);
        mxy = max(y, mxy);
      }
    }
    if (u != 1 && mxx < dep[u] && mxy - dep[u] <= d - 1) ans -= 2;
    if (u != 1 && mxy < dep[u] && mxx - dep[u] <= d - 1) ans -= 2;
    return {mxx, mxy};
  };
  dfs(dfs, 1, 0);
  cout << ans << '\n';

  return 0;
}