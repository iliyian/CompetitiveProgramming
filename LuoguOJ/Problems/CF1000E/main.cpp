#include <bits/stdc++.h>
#define N 300003
using namespace std;

vector<vector<int>> g, sccg;

int dfn[N], low[N], cnt = 0, s[N], tp = 0, sc = 0, scc[N];
bitset<N> ins;

void tarjan(int u, int prev) {
  dfn[u] = low[u] = ++cnt;
  ins[u] = true;
  s[++tp] = u;
  for (int v : g[u]) {
    if (v == prev) continue;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (ins[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    sc++;
    do {
      ins[s[tp]] = false;
      scc[s[tp]] = sc;
    } while (s[tp--] != u);
  }
}

int dis[N], maxd = -1, r = -1;

void dfs(int u, int prev) {
  dis[u] = dis[prev] + 1;
  if (dis[u] > maxd) {
    maxd = dis[u];
    r = u;
  }
  for (int v : sccg[u]) {
    if (prev == v) continue;
    dfs(v, u);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
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
  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i, 0);
  sccg.resize(sc + 1);
  for (int i = 1; i <= n; i++)
    for (int v : g[i])
      if (scc[i] != scc[v])
        sccg[scc[i]].push_back(scc[v]);
  
  memset(dis, 0, sizeof(dis));
  dfs(1, 0);
  memset(dis, 0, sizeof(dis));
  dfs(r, 0);
  cout << maxd - 1;
  return 0;
}