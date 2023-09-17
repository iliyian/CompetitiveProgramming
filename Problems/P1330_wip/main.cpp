// 位运算优先级为什么这么低？

#include <bits/stdc++.h>
using namespace std;

int color[10001], n, m;
bitset<10001> vis;
vector<vector<int>> g;

int bfs() {
  queue<int> q;
  memset(color, 0x3f, sizeof(color));
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (color[i] == 0x3f3f3f3f) {
      color[i] = 0;
      int cnt = 1;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
          if (color[v] == (color[u] ^ 1)) continue;
          if (color[v] == color[u]) {
            return 0x3f3f3f3f;
          }
          color[v] = color[u] ^ 1;
          q.push(v);
          cnt += color[v];
        }
      }
      ans += cnt;
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
  int ans = bfs();
  if (ans == 0x3f3f3f3f)
    cout << "Impossible";
  else
    cout << ans;
  return 0;
}