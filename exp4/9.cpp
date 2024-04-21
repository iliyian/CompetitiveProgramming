#include <bits/stdc++.h>
#define N 1005
using namespace std;

vector<vector<int>> g;
bitset<N> vis;

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  cout << u << ' ';
  for (int v : g[u])
    dfs(v);
}

void solve() {
  int n, m, s;
  cin >> n >> m >> s;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  for (auto &ed : g)
    sort(ed.begin(), ed.end());
  dfs(s);
  if (vis.count() < n)
    cout << "\nNon-connected";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("9.in", "r", stdin);
  freopen("9.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}