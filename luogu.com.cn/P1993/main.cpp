// xi - xj <= c  ->  g[j].push_back({i, c});
// cnt[v]++ 在不在判定 vis[v] 的 if 里面都没关系

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

bitset<5001> vis ;

int dis[5001], cnt[5001], n, m;

struct Node {
  int u, d;
};
queue<Node> q;

void spfa() {
  dis[0] = 0; vis[0] = 1;
  q.push({0, dis[0]});
  for (int i = 0; i <= n; i++) g[0].push_back({i, 0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int u = node.u, d = node.d;
    vis[u] = false;
    for (auto &ed : g[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (++cnt[v] >= n + 1) {
          cout << "No";
          exit(0);
        }
        if (!vis[v]) q.push({v, dis[v]}), vis[v] = true;
      }
    }
  }
  cout << "Yes";
  exit(0);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  g.resize(n + 1);
  memset(dis, 0x3f, sizeof(dis));
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < m; i++) {
    int op, a, b, c;
    cin >> op;
    if (op == 1) {
      cin >> a >> b >> c;
      g[a].push_back({b, -c});
    } else if (op == 2) {
      cin >> a >> b >> c;
      g[b].push_back({a, c});
    } else {
      cin >> a >> b;
      g[a].push_back({b, 0});
      g[b].push_back({a, 0});
    }
  }
  spfa();
  return 0;
}