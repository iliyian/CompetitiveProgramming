// dijstra不开堆优化没有意义

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int u, dis;
  bool operator < (const Node &b) const {return dis > b.dis;}
};

vector<vector<int>> e;
priority_queue<Node> q;
bitset<1000001> vis;
int dis[1000001], ans[1000001];

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  e.resize(n + 1);
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= n; i++) dis[i] = 1 << 30;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  q.push({1, 0});
  dis[1] = 0;
  ans[1] = 1;
  while (!q.empty()) {
    int u = q.top().u; q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto v : e[u]) {
      if (vis[v]) continue;
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        ans[v] = ans[u];
        q.push({v, dis[v]});
      } else if (dis[v] == dis[u] + 1) {
        ans[v] = (ans[v] + ans[u]) % 100003;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << '\n';
  return 0;
}