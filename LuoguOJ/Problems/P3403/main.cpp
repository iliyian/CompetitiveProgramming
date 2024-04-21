// date: 2024/01/27 21:34:15
// tag: 同余最短路， https://oi-wiki.org/graph/mod-shortest-path
// wip

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

struct Node {
  int u, dis;
  bool operator < (const Node &b) const {
    return dis > b.dis;
  }
};

vector<int> f;
vector<bool> vis;

void solve() {
  int h, x, y, z;
  cin >> h >> x >> y >> z;
  g.resize(x);
  vis.resize(x);
  f.resize(x);
  if (x == 1 || y == 1 || z == 1) {
    cout << h;
    return;
  }
  for (int i = 0; i < x; i++)
    g[i].push_back({(i + y) % x, y}),
    g[i].push_back({(i + z) % x, z});

  priority_queue<Node> q;
  fill(f.begin(), f.end(), inf);
  f[1] = 1;
  q.push({1, 1});

  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u;
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [v, w] : g[u]) {
      if (f[v] > f[u] + w) {
        f[v] = f[u] + w;
        q.push({v, f[v]});
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < x; i++)
    if (h >= f[i])
      ans += (h - f[i]) / x + 1;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}