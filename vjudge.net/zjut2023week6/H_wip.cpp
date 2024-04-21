#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

void dfs(int u, int prev) {

  for (int v : g[u])
    if (v != prev)
      dfs(v, u);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("H.in", "r", stdin);
  int n;
  g.resize(n + 1);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
}