// low表示可以由之到达的最早的父节点
// dfn表示父节点

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;
vector<vector<int>> g;

int parent[151], dfn[151], low[151], dfs_cnt = 0;

void tarjan(int u, int pa) {
  parent[u] = pa;
  dfn[u] = low[u] = ++dfs_cnt;
  for (int v : g[u]) {
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) { // 等于则回到父节点
        ans.push_back({u, v});
      }
    } else if (dfn[v] < dfn[u] && v != pa) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i])
      tarjan(i, i);
  }
  sort(ans.begin(), ans.end());
  for (auto e : ans) {
    cout << e.first << ' ' << e.second << '\n';
  }
  return 0;
}