// date: 2024-04-02 13:12:24
// tag: 搜索
// wa#01: 只考虑了父节点而非祖节点的情况
// wa#02, #03: 应该在每次调用dfs时更新ans而非dfs递归到头时

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, p;
  cin >> n >> p;
  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= p; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> dep(n + 1), pa(n + 1), siz(n + 1);
  vector<vector<int>> nodes(n + 1);
  int maxdep = -1;
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    nodes[dep[u]].push_back(u);
    maxdep = max(maxdep, dep[u]);
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        pa[v] = u;
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
  };
  dfs(dfs, 1, 0);

  vector<bool> cut(n + 1);

  int sum = 0, ans = INT_MAX;
  auto dfs2 = [&](auto self, int u, bool tag) -> void {
    cut[u] = tag;
    for (int v : g[u]) {
      if (v != pa[u]) {
        self(self, v, tag);
      }
    }
  };

  int cutcnt = 0;
  auto dfs3 = [&](auto self, int d) {
    if (d == maxdep + 1) {
      return;
    }
    for (auto u : nodes[d]) {
      if (!cut[u]) {
        dfs2(dfs2, u, true);
        cutcnt += siz[u];
        ans = min(ans, n - cutcnt);
        self(self, d + 1);
        cutcnt -= siz[u];
        dfs2(dfs2, u, false);
      }
    }
  };
  dfs3(dfs3, 2);

  cout << ans << '\n';

  return 0;
}