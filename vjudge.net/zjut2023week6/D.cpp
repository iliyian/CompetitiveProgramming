#include <bits/stdc++.h>
#define N 5005
#define mod 80112002
using namespace std;

int f[N];

vector<vector<int>> g;
bitset<N> in;

int dfs(int u) {
  if (f[u]) return f[u];
  if (g[u].empty()) return f[u] = 1;
  for (int v : g[u])
    f[u] = (f[u] + dfs(v)) % mod;
  return f[u] % mod;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    in[v] = true;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!in[i])
      ans = (ans + dfs(i)) % mod;
  cout << ans;
}