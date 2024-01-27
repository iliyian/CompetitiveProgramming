// date: 2024/01/27 19:16:02
// tag: A*求k短路，比较模板
// 顺便A*算法比那种同时更新d1和d2数组的方法还更好写

#include <bits/stdc++.h>
#define N 5005
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;
bitset<N> vis;
int cnt[N], h[N];

struct Node {
  int u, dis;
  bool operator < (const Node &b) const {
    return dis > b.dis;
  }
};

struct Node2 {
  int u, d;
  bool operator < (const Node2 &b) const {
    return d + h[u] > b.d + h[b.u];
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w}), g[v].push_back({u, w});
  }
  priority_queue<Node> q;
  fill(h + 1, h + 1 + n, 0x3f3f3f3f);
  h[n] = 0;
  q.push({n, 0});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u, d = node.dis;
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [v, w] : g[u]) {
      if (h[v] > h[u] + w) {
        h[v] = h[u] + w;
        q.push({v, w});
      }
    }
  }

  priority_queue<Node2> q2;
  q2.push({1, 0});
  while (!q2.empty()) {
    Node2 node = q2.top(); q2.pop();
    int u = node.u, d = node.d;
    cnt[u]++;
    if (u == n && cnt[u] == 2) {
      cout << d << '\n';
      return;
    }
    if (cnt[u] > 2) continue;
    for (auto [v, w] : g[u])
      q2.push({v, w + d});
  }
  cout << -1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}