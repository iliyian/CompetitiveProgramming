// 限定条件太少了，简单到爆炸，主要是SPJ功劳

#include <bits/stdc++.h>
using namespace std;

int c[200001];
bitset<200001> vis;
vector<vector<int>> g;

void bfs(int u) {
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    u = q.front(); q.pop();
    for (int v : g[u]) {
      if (!vis[v]) {
        q.push(v);
        vis[v] = true;
        c[v] = c[u] ^ 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(c, 0, sizeof(c));

  for (int i = 1; i <= n; i++) {
    if (g[i].empty()) {
      cout << "NIE";
      return 0;
    }
  }

  cout << "TAK" << '\n';

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) vis[i] = true, bfs(i);
  }

  for (int i = 1; i <= n; i++) {
    cout << (c[i] ? 'S' : 'K') << '\n';
  }
  return 0;
}