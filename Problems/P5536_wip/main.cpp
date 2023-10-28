#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

int pa[100001], rstep[100001], r = 0, maxd[100001], dep[100001], ans[100001];

void dfs(int u, int prev) {
  for (int v : g[u]) {
    if (v == prev) continue;
    rstep[u] = rstep[v] + 1;
    if (rstep[u] > rstep[r]) r = u;
    dfs(v, u);
  }
}

void dfsd(int u, int prev) {
  maxd[u] = dep[u] = dep[prev] + 1;
  for (int v : g[u]) {
    if (v == prev) continue;
    pa[v] = u;
    dfsd(v, u);
    maxd[u] = max(maxd[u], maxd[v]);
  }
}

int main() {
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
  rstep[r] = 0;
  dfs(r, 0);
  int mid = r;
  for (int i = 0; i < (rstep[r] - 1) / 2 + 1; i++)
    mid = pa[mid];
  // ???

  dfsd(mid, 0);

  for (int i = 1; i <= n; i++) ans[i] = maxd[i] - dep[i];
  sort(ans + 1, ans + 1 + n);
  cout << ans[n - k] + 1;
  return 0;
}