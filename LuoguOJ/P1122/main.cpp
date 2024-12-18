#include <bits/stdc++.h>
using namespace std;

int a[16001], f[16001];
vector<vector<int>> g;

void dfs(int u, int pa) {
  f[u] = a[u];
  for (int v : g[u]) {
    if (v != pa) {
      dfs(v, u);
      f[u] += (f[v] > 0 ? f[v] : 0);
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  int ans = -0x7fffffff;
  for (int i = 1; i <= n; i++)
    ans = max(ans, f[i]);
  cout << ans;
  return 0;
}