#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
array<vector<Edge>, 53> g;

struct Node {
  int u, d;
  bool operator < (const Node &b) const {return d > b.d;}
};
priority_queue<Node> q;

int convert(char c) {
  return isupper(c) ? c - 'A' + 1 : c - 'a' + 27;
}

bitset<53> vis;
int dis[53], inf = 0x7fffffff;

int main() {
  freopen("data.in", "r", stdin);
  int P;
  cin >> P;
  for (int i = 0; i < P; i++) {
    char u, v;
    int w;
    cin >> u >> v >> w;
    g[convert(v)].push_back({convert(u), w});
    g[convert(u)].push_back({convert(v), w});
  }
  for (int i = 1; i <= 53; i++) dis[i] = inf;
  dis[26] = 0;
  q.push({26, 0});

  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int u = node.u;
    if (vis[u]) continue;
    vis[u] = true;

    for (auto &ed : g[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({v, dis[v]});
      }
    }
  }

  char ans;
  int minn = inf;
  for (int i = 1; i <= 25; i++) {
    if (dis[i] < minn) {
      minn = dis[i];
      ans = i > 26 ? char(i - 27 + 'a') : char(i - 1 + 'A');
    }
  }
  cout << ans << ' ' << minn;
  return 0;
}