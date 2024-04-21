#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};

vector<vector<Edge>> g;

int f[101][101], sz[101], N, Q;

void dfs(int u, int pa) {
  for (auto &ed : g[u]) {
    int v = ed.v, w = ed.w;
    if (v == pa) continue;
    dfs(v, u);
    sz[u] += sz[v] + 1;
    for (int j = min(sz[u], Q); j >= 1; j--)
      for (int k = min(sz[v], j - 1); k >= 0; k--)
        f[u][j] = max(f[u][j], f[u][j - k - 1] + f[v][k] + w);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> N >> Q;
  g.resize(N + 1);
  for (int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs(1, 0);
  cout << f[1][Q];
  return 0;
}