#include <bits/stdc++.h>
#define int long long
#define N 1005
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Edge {
  int v, w;
};
vector<Edge> g[N];
int t1[N][N], dis[N], cnt[N], s, t, n, m;
bitset<N> vis;

void spfa() {
  fill(dis, dis + N, inf);
  vis[s] = true, dis[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vis[u] = false;
    for (auto &[v, w] : g[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> t1[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      g[i].push_back({x, -t1[i][j]});
    }
  }
  s = 1, t = n + 1;

  spfa();
  cout << -dis[t] << '\n';

  return 0;
}