#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

int in[1501], f[1501][1501];
bitset<1501> vis;

int calc(int u) {
  for (int v : g[u]) {
    if (vis[v]) continue;
    vis[v] = true;
    calc(v);
    f[u][0] += f[v][1];
    f[u][1] += min(f[v][0], f[v][1] + 1);
  }
  return min(f[u][0], f[u][1] + 1);
}

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  g.resize(n + 1);
  memset(in, 0, sizeof(in));
  for (int i = 0; i <= n; i++) memset(f[i], 0, sizeof(f[i]));
  for (int i = 0; i < n; i++) {
    int u, k, v;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v;
      g[u].push_back(v), in[v]++;
    }
  }
  for (int i = 0; i < n; i++)
    if (!in[i]) {
      cout << calc(i);
      return 0;
    }
}