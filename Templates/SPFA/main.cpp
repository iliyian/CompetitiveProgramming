#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};

vector<vector<Edge>> e;
queue<int> q;
bitset<2001> vis;
int dis[2001], cnt[2001];

void solve() {
  int n, m;
  cin >> n >> m;

  e.clear();
  e.resize(n + 1);
  while (!q.empty()) q.pop();
  vis.reset();
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) dis[i] = 1 << 30;
  dis[1] = 0;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    if (w >= 0) e[v].push_back({u, w});
  }
  q.push(1);
  vis[1] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vis[u] = false;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v] = cnt[u] + 1;
        if (cnt[v] >= n) {
          cout << "YES\n";
          return;
        }
        if (!vis[v]) q.push(v), vis[v] = true;
      }
    }
  }
  cout << "NO\n";
}

int main() {
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}