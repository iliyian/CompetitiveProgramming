#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

bitset<21> vis;
int f[21];

int dfs(int u) {
  int sum = 0;
  for (auto &ed : g[u]) {
    int v = ed.v, w = ed.w;
    if (vis[v]) continue;
    vis[v] = true;
    sum = max(sum, dfs(v) + w);
    vis[v] = false;
  }
  return sum;
}

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  memset(f, 0, sizeof(f));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  int ans = -1;
  for (int i = 1; i <= n; i++) {
    vis[i] = true;
    ans = max(ans, dfs(i));
    vis[i] = false;
  }
  cout << ans;
  return 0;
}