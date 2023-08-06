#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
array<int, 100> sz, dp, w;

void dfs(int u, int pa, int dep) {
  sz[u] = w[u];
  for (auto v : g[u]) {
    if (v == pa) continue;
    dfs(v, u, dep + 1);
    sz[u] += sz[v];
  }
  dp[1] += dep * w[u];
}

int ans = 1 << 30;

void dpfunc(int u, int pa) {
  for (auto v : g[u]) {
    if (v == pa) continue;
    dp[v] = dp[u] + sz[1] - 2 * sz[v];
    dpfunc(v, u);
  }
  ans = min(ans, dp[u]);
}

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> w[i] >> a >> b;
    if (a) g[i].push_back(a), g[a].push_back(i);
    if (b) g[i].push_back(b), g[b].push_back(i);
  }
  dfs(1, 0, 0);
  dpfunc(1, 0);

  cout << ans;
  return 0;
}