#include <bits/stdc++.h>
#define int long long
// 多亏了上面这行
using namespace std;

vector<vector<int>> g;
int pa[50001][21], dep[50001], f[50001];

void dfs(int u, int fa) {
  pa[u][0] = fa, dep[u] = dep[fa] + 1;
  for (int i = 1; i <= 20; i++)
    pa[u][i] = pa[pa[u][i - 1]][i - 1];
  for (int v : g[u]) {
    if (v == fa) continue;
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

int ans = -0x3f3f3f3f;

void query(int u, int prev) {
  for (int v : g[u]) {
    if (v == prev) continue;
    query(v, u);
    f[u] += f[v];
  }
  ans = max(ans, f[u]);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 0; i < k; i++) {
    int s, t;
    cin >> s >> t;
    int lcan = lca(s, t);
    f[s]++, f[t]++, f[lcan]--, f[pa[lcan][0]]--;
  }
  query(1, 0);
  cout << ans;
  return 0;
}