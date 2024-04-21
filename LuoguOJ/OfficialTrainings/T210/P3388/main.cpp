// 根节点有两个孩子一定是
// low >= dfn 且非根结点一定是

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int dfn[20001], low[20001], parent[20001], dfs_cnt = 0, ans = 0;
bitset<20001> vis, is_cutpoint;

void tarjan(int u, int pa) {
  parent[u] = pa;
  dfn[u] = low[u] = ++dfs_cnt;
  vis[u] = true;
  int child = 0;
  for (int v : g[u]) {
    if (!vis[v]) {
      child++;
      tarjan(v, u);
      low[u] = min(low[u], low[v]); // 一般更新
      if (u != pa && low[v] >= dfn[u] && !is_cutpoint[u]) // 判定条件，只有前两个
        is_cutpoint[u] = true, ans++;
    } else if (v != pa) // 回到非根，更新
      low[u] = min(low[u], dfn[v]);
  }
  if (u == pa && child >= 2 && !is_cutpoint[u])
    is_cutpoint[u] = true, ans++;
}

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i])
      tarjan(i, i);
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; i++)
    if (is_cutpoint[i])
      cout << i << ' ';
  return 0;
}