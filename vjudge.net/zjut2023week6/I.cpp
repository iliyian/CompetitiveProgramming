#include <bits/stdc++.h>
#define N 500005
using namespace std;

vector<vector<int>> g;
int pa[N][31], dep[N];

void dfs(int u, int prev) {
  pa[u][0] = prev, dep[u] = dep[prev] + 1;
  for (int i = 1; i < 31; i++)
    pa[u][i] = pa[pa[u][i - 1]][i - 1];
  for (int v : g[u])
    if (v != prev)
      dfs(v, u);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("I.in", "r", stdin);
  int n, m, s;
  cin >> n >> m >> s;
  g.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(s, 0);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 30; i >= 0; i--)
      if (dep[u] - (1 << i) >= dep[v])
        u = pa[u][i];
    if (u == v) {
      cout << u << '\n';
      continue;
    }
    for (int i = 30; i >= 0; i--)
      if (pa[u][i] != pa[v][i])
        u = pa[u][i], v = pa[v][i];
    cout << pa[u][0] << '\n';
  }
}