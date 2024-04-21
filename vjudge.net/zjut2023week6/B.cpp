#include <bits/stdc++.h>
#define N 100005
using namespace std;

vector<vector<int>> g;
int ans[N];

void dfs(int u, int ori) {
  if (ans[u]) return;
  ans[u] = ori;
  for (auto v : g[u])
    dfs(v, ori);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[v].push_back(u);
  }
  for (int i = n; i >= 1; i--)
    dfs(i, i);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  return 0;
}