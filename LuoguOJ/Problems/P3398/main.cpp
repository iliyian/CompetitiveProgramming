#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int pa[100001][21], dep[100001];

void dfs(int u, int prev) {
  dep[u] = dep[prev] + 1, pa[u][0] = prev;
  for (int i = 1; (1 << i) <= dep[u]; i++)
    pa[u][i] = pa[pa[u][i - 1]][i - 1];
  for (int v : g[u]) {
    if (v == prev) continue;
    dfs(v, u);
  }
}

int lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int i = 20; i >= 0; i--)
    if (dep[u] <= dep[v] - (1 << i))
      v = pa[v][i];
  if (u == v) return u;
  for (int i = 20; i >= 0; i--)
    if (pa[u][i] != pa[v][i])
      u = pa[u][i], v = pa[v][i];
  return pa[u][0];
}

int dis(int u, int v) {
  return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, q;
  cin >> n >> q;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int lca1 = lca(a, b), lca2 = lca(c, d);
    if (dis(a, b) == dis(a, lca2) + dis(b, lca2) || dis(c, d) == dis(c, lca1) + dis(d, lca1))
      cout << "Y\n";
    else
      cout << "N\n";
  }
  return 0;
}