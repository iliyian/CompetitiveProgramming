// date: 2023/12/10
// tag: dp on tree, siz数组真是树上极其重要的数组
// wa#01: 搞错逻辑了

#include <bits/stdc++.h>
#define N 100005
using namespace std;

vector<vector<int>> g;
int d[N], siz[N], n;

void dfs(int u, int prev, int len) {
  d[1] += len;
  siz[u] = 1;
  for (int v : g[u])
    if (v != prev) {
      dfs(v, u, len + 1);
      siz[u] += siz[v];
    }
}

int ans = 0x3f3f3f3f, id = -1;
void dp(int u, int prev) {
  if (ans > d[u] || ans == d[u] && u < id) {
    ans = d[u], id = u;
  }
  for (int v : g[u]) {
    if (v == prev) continue;
    d[v] = d[u] + (n - siz[v] - siz[v]) * (1);
    dp(v, u);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("H.in", "r", stdin);
  cin >> n;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(1, 0, 0);
  dp(1, 0);
  cout << id << ' ' << ans;
}