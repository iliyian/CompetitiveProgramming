// date: 2023/12/23 19:52:51
// tag: 注意某特殊的环，即n个点n个边，刚好是树多一条边，恰好一个环
// 顺便树上距离得bfs，不是dfs，不然剖分？

#include <bits/stdc++.h>
#define N 200005
using namespace std;

vector<vector<int>> g;
int n, a, b, ent;
bitset<N> vis;

void dfs(int u, int pre) {
  if (vis[u]) {
    if (!ent) ent = u;
    return;
  }
  vis[u] = true;
  for (int v : g[u])
    if (v != pre) {
      dfs(v, u);
    }
}

int bfs(int s, int t) {
  vis.reset();
  queue<pair<int, int>> q;
  q.push({s, 0});
  while (!q.empty()) {
    int u = q.front().first, d = q.front().second; q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    if (u == t) return d;
    for (int v : g[u])
      q.push({v, d + 1});
  }
  return -1;
}

void solve() {
  cin >> n >> a >> b;
  g.clear();
  g.resize(n + 1);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  ent = 0;
  vis.reset();
  dfs(b, 0);

  if (a == b || bfs(a, ent) <= bfs(b, ent)) {
    cout << "NO\n";
  } else cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}