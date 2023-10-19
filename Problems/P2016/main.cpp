#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

int f[1501][2];

void dfs(int u, int pa) {
  f[u][1] = 1, f[u][0] = 0;
  for (int v : g[u]) {
    if (v == pa) continue;
    dfs(v, u);
    f[u][0] += f[v][1];
    f[u][1] += min(f[v][1], f[v][0]);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 0; i < n; i++) {
    int u, k, v;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  dfs(0, -1);
  cout << min(f[0][0], f[0][1]);
  return 0;
}