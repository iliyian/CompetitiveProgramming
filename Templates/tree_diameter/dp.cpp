#include <bits/stdc++.h>
#define N 200005
using namespace std;

struct Edge {
  int v, w;
};

vector<vector<Edge>> g;

int d1[N], d2[N], d = 0;

void dfs(int u, int prev) {
  for (auto &[v, w] : g[u]) {
    if (v == prev) continue;
    dfs(v, u);
    int t = d1[v] + 1;
    if (t > d1[u]) {
      d2[u] = d1[u], d1[u] = t;
    } else if (t > d2[u])
      d2[u] = t;
  }
  d = max(d, d1[u] + d2[u]);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs(1, 0);
  // 原题不能这样做，因为如果要找树上最大的AB+BC,C不一定在AB上，但这样直径可以用于负权树
  // cout << 2 * d - (d - 1) / 2 + 1;
  cout << d;
  return 0;
}