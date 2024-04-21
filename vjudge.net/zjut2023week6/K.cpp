#include <bits/stdc++.h>
#define N 5005
using namespace std;

vector<vector<int>> g;
bitset<N> vis;
bool ans = false;

void dfs(int u, int pa, int ppa) {
  if (vis[u]) return;
  vis[u] = true;
  for (int v : g[u]) {
    if (v == ppa) ans = true;
    dfs(v, u, pa);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("K.in", "r", stdin);
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    g[i].push_back(v);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i])
      dfs(i, 0, 0);
  cout << (ans ? "YES": "NO") << '\n';
}