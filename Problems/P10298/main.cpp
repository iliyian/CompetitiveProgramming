// date: 2024-04-01 18:17:54
// tag: 生成树

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<vector<tuple<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back({y, i});
    g[y].push_back({x, i});
  }

  vector<int> col(m + 1, -1);
  vector<bool> vis(n + 1);
  auto dfs = [&](auto self, int u, int p, int c) -> void {
    for (auto &[v, id] : g[u]) {
      if (v != p && !vis[v]) {
        col[id] = c;
        vis[v] = true;
        self(self, v, u, c ^ 1);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      vis[i] = true;
      dfs(dfs, i, 0, 0);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (col[i] == 1) {
      cout << "R";
    } else if (col[i] == 0) {
      cout << "B";
    } else {
      cout << "G";
    }
  }

  return 0;
}