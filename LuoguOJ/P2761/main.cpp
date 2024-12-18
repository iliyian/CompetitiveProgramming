// date: 2024-04-09 17:46:34
// tag: 状压dijkstra

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int u, d;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

bitset<1050000> vis;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<int> dis(1 << n, INT_MAX);
  vector<array<int, 5>> g(m);
  for (int i = 0; i < m; i++) {
    int w;
    cin >> w;
    string a, b;
    cin >> a >> b;
    int b1 = 0, b2 = 0, f1 = 0, f2 = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] == '+') b1 |= 1 << j;
      if (a[j] == '-') b2 |= 1 << j;
      if (b[j] == '-') f1 |= 1 << j;
      if (b[j] == '+') f2 |= 1 << j;
    }
    g[i] = {b1, b2, f1, f2, w};
  }

  priority_queue<Node> q;
  q.push({(1 << n) - 1, 0});
  dis[(1 << n) - 1] = 0;
  while (!q.empty()) {
    auto [u, t] = q.top(); q.pop();
    if (u == 0) {
      cout << t << '\n';
      return 0;
    }
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [b1, b2, f1, f2, w] : g) {
      if (b1 && ((b1 | u) != u)) continue;
      if (b2 & u) continue;
      int v = ~(~u | f1) | f2;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({v, dis[v]});;
      }
    }
  }
  cout << 0 << '\n';

  return 0;
}