#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int ans = 0;

void dfs(int u, int cur, int prev) {
  if (cur < 0) return;
  ans++;
  for (int v : g[u])
    if (v != prev)
      dfs(v, cur - 1, u);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  int n, d;
  cin >> n >> d;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, d, 0);
  cout << ans - 1;
}