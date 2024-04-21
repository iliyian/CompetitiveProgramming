#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g, scg;

array<int, 10001> a, dfn, low, s, in, dist, scc, sca, f;
bitset<10001> ins, vis;
int cnt = 0, tp = 0, sc = 0;

void tarjan(int u) {
  dfn[u] = low[u] = ++cnt;
  ins[u] = true;
  s[++tp] = u;
  for (int v : g[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (ins[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    sc++;
    do {
      ins[s[tp]] = false;
      scc[s[tp]] = sc;
    } while (s[tp--] != u);
  }
}

void dfs(int u) {
  if (f[u]) return;
  f[u] = sca[u];
  int sum = 0;
  for (int v : scg[u]) {
    dfs(v);
    sum = max(sum, f[v]);
  }
  f[u] += sum;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  g.resize(n + 1);
  scg.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i);

  for (int i = 1; i <= n; i++)
    sca[scc[i]] += a[i];

  queue<int> q;

  for (int i = 1; i <= n; i++)
    for (int v : g[i])
      if (scc[i] != scc[v])
        scg[scc[i]].push_back(scc[v]);
  
  int ans = -1;
  for (int i = 1; i <= sc; i++)
    dfs(i), ans = max(ans, f[i]);
  cout << ans;
  return 0;
}