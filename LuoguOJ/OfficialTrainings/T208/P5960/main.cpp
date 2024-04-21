#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> e;

queue<int> q;
bitset<5001> vis;
int dis[5001], cnt[5001];

int main() {
  int n, m;
  cin >> n >> m;
  e.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[v].push_back({u, w});
  }

  for (int i = 1; i <= n; i++) {
    e[0].push_back({i, 0});
    dis[i] = 1 << 30;
  }
  memset(cnt, 0, sizeof(cnt));
  dis[0] = 0;

  q.push(0);
  vis[0] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vis[u] = false;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v]++; // 确实不能用cnt[v]=cnt[u]+1,
        if (cnt[v] >= n) {
          cout << "NO";
          return 0;
        }
        if (!vis[v]) q.push(v), vis[v] = true;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << ' ';
  }
  return 0;
}