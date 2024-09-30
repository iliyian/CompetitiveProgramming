// date: 2024/02/17 16:17:30
// tag: 多重图的思想十分常见，关键在于要维护距离之外的信息，
// dp也这样，多重信息就得多维
// 前者例如买卖物品的三重图
// 只要空间允许就得这么做，否则答案不完全
// 顺便不开全局数组就不用清了，一些极端情况下这样甚至可以避免被T...
// 别tmd写个solve类了
// 感谢样例

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Edge {
  int v, w;
};

struct Node {
  int u, dis, curs;
  bool operator < (const Node &b) const {
    return dis > b.dis;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w}), g[v].push_back({u, w});
  }
  vector<int> s(n + 1);
  vector<vector<int>> dis(n + 1, vector<int>(1001, inf));
  vector<vector<bool>> vis(n + 1, vector<bool>(1001, false));
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  priority_queue<Node> q;
  q.push({1, 0, s[1]});
  dis[1][s[1]] = 0;
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u, c = node.curs, d = node.dis;
    if (vis[u][c] || u == n) continue;
    for (auto [v, w] : g[u]) {
      int x = min(c, s[v]);
      if (dis[v][x] > dis[u][c] + w * c) {
        dis[v][x] = dis[u][c] + w * c;
        q.push({v, dis[v][x], x});
      }
    }
  }
  int ans = inf;
  for (int i = 1; i <= 1000; i++) {
    if (dis[n][i]) {
      ans = min(ans, dis[n][i]);
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}