#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
array<int, 10001> dfn, low, st, scc, scout, sz;
int dfs_cnt = 0, tp = 0, sc = 0;
bitset<10001> in_stack, vis;

void tarjan(int u) {
  dfn[u] = low[u] = ++dfs_cnt;
  in_stack[u] = true;
  st[++tp] = u;
  for (int v : g[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stack[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++sc;
    do {
      in_stack[st[tp]] = false;
      scc[st[tp]] = sc;
      sz[sc]++;
    } while (st[tp--] != u);
  }
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
  }

  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i);

  for (int i = 1; i <= n; i++) {
    for (int v : g[i])
      if (scc[v] != scc[i])
        scout[scc[i]]++;
  }
  int anssc = 0;
  for (int i = 1; i <= sc; i++) {
    if (!scout[i]) {
      if (anssc) {
        cout << 0;
        return 0;
      }
      anssc = i;
    }
  }

  cout << sz[anssc];
  return 0;
}