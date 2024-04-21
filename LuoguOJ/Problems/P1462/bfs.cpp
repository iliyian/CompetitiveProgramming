#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
  int v, c;
};
vector<vector<Edge>> g;

struct Node {
  int u, life, maxf;
  bool operator < (const Node &b) const {
    return maxf > b.maxf;
  }
};
priority_queue<Node> q;

int f[10001], visb[10001];

signed main() {
  freopen("data.in", "r", stdin);
  int n, m, b;
  cin >> n >> m >> b;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }
  memset(visb, 0x3f, sizeof(visb));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  q.push({1, b, f[1]});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u, life = node.life, maxf = node.maxf;
    if (u == n) {
      cout << maxf;
      return 0;
    }
    if (life < 0) continue;
    if (visb[u] <= life && maxf <= f[u]) continue;
    visb[u] = life;
    for (auto &ed : g[u]) {
      int v = ed.v, c = ed.c;
      q.push({v, life - c, max(maxf, f[v])});
    }
  }
  cout << "AFK";
  return 0;
}