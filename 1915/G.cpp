#include <bits/stdc++.h>
#define N 1005
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Edge {
  int v, w;
};

struct Node {
  int dis, u, s;
  bool operator < (const Node &b) const {
    return dis > b.dis;
  }
};

struct Sol {
  vector<vector<Edge>> g;
  vector<vector<Edge>> sg;
  vector<int> s;
  bitset<N> vis;
  int dis[N], n, m;

  int dijkstra() {
    priority_queue<Node> q;
    q.push({0, 1, s[1]});
    fill(dis + 1, dis + n + 1, inf);
    dis[1] = 0;
    int ans = inf;
    while (!q.empty()) {
      Node node = q.top(); q.pop();
      int u = node.u, curs = node.s;
      if (u == n) {
        ans = min(ans, node.dis);
        continue;
      }
      if (vis[u]) continue;
      vis[u] = true;
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w * curs) {
          dis[v] = dis[u] + w * curs;
          q.push({dis[v], v, min(curs, s[v])});
        }
      }
    }
    return ans;
  }

  void solve() {
    cin >> n >> m;
    g.resize(n + 1), s.resize(n + 1);
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++)
      cin >> s[i];
    cout << dijkstra() << '\n';
  }
};

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);
  int _; cin >> _;
  while (_--) Sol{}.solve();
}