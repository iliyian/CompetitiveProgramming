// 位运算优先级为什么这么低？

#include <bits/stdc++.h>
using namespace std;

int color[10001], n, m;
vector<vector<int>> g;

void restore(int s, int clr) {
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (color[u] == 0x3f3f3f3f) continue;
    color[u] = 0x3f3f3f3f;
    for (int v : g[u])
      q.push(v);
  }
}

int bfs(int s, int clr) {
  queue<int> q;
  color[s] = clr;
  q.push(s);
  int ans = clr;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
      if (color[v] == 0x3f3f3f3f) {
        q.push(v);
        color[v] = color[u] ^ 1;
        ans += color[v];
      } else if (color[v] == color[u]) {
        restore(s, clr);
        return 0x3f3f3f3f;
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(color, 0x3f, sizeof(color));
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (color[i] == 0x3f3f3f3f);
      ans += min(bfs(i, 1), bfs(i, 0));
  }
  cout << ans;
  return 0;
}