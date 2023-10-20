#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, idx;
};

vector<vector<Edge>> g;

int vis[200001], f[200001];

void dfs(int u) {
  for (auto &ed : g[u]) {
    int v = ed.v, idx = ed.idx;
    if (f[v]) continue;
    vis[v] = idx;
    f[v] = f[u] + (idx <= vis[u]);
    dfs(v);
  }
}

void solve() {
  int n;
  cin >> n;
  memset(vis, 0, sizeof(vis));
  memset(f, 0, sizeof(f));
  f[1] = 1;
  g.assign(n + 1, vector<Edge>());
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  dfs(1);
  int ans = -1;
  for (int i = 1; i <= n; i++)
    ans = max(ans, f[i]);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}