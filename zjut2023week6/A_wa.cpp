#include <bits/stdc++.h>
#define N 100005
using namespace std;

bitset<N> vis;
vector<vector<int>> g;

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  cout << u << ' ';
  for (auto v : g[u])
    dfs(v);
}

void bfs() {
  // priority_queue<int, vector<int>, greater<int>> q;
  // 什么tmd表述不清的破题目
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    cout << u << ' ';
    for (auto v : g[u])
      q.push(v);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  for (auto eds : g)
    sort(eds.begin(), eds.end());
  
  vis.reset();
  dfs(1);
  cout << '\n';

  vis.reset();
  bfs();
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  // int t; cin >> t;
  int t = 1;
  while (t--) solve();
  return 0;
}