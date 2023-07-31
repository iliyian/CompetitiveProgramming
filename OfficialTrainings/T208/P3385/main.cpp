#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};

vector<vector<Edge>> e;
bitset<2001> vis;
queue<int> q;
int cnt[2001], dis[2001];

void solve() {
  int n, m;
  cin >> n >> m;
  e.clear();
  e.resize(n + 1);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) dis[i] = 1 << 30;
  dis[1] = 0;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    if (w > 0) e[v].push_back({u, w});
  }
  q.push(1);
  vis[1] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    // if (vis[u]) continue;
    vis[u] = false;
    for (auto ed : e[u]) {
      int v = ed.v;
      if (ed.w + dis[u] < dis[v]) {
        cnt[v] = cnt[u] + 1;
        if (cnt[v] >= n) {
          cout << "YES";
          return;
        }
        dis[v] = dis[u] + ed.w;
        if (!vis[v]) q.push(v), vis[v] = true;
      }
    }
  }
  cout << "NO";
  return;
}

int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}