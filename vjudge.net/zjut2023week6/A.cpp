// date: 2023/12/10
// wa#01: 用范围循环排序的时候，tmd忘记加用引用了

#include <bits/stdc++.h>
#define N 100005
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

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  for (auto &u : g)
    sort(u.begin(), u.end());
  dfs(1);
  cout << '\n';

  vis.reset();
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    cout << u << ' ';
    for (int v : g[u])
      q.push(v);
  }
}