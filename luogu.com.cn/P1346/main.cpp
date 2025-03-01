#include <bits/stdc++.h>
using namespace std;

struct Node {
  int u, t;
  bool operator < (const Node &b) const {
    return t > b.t;
  }
};
priority_queue<Node> q;

bitset<101> vis;
vector<vector<int>> g;

int main() {
  freopen("data.in", "r", stdin);
  int n, S, T;
  cin >> n >> S >> T;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      g[i].push_back(v);
    }
  }
  q.push({S, 0});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u, t = node.t;
    if (u == T) {
      cout << t;
      return 0;
    }
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (i == 0) q.push({v, t});
      else q.push({v, t + 1});
    }
  }
  cout << -1;
  return 0;
}