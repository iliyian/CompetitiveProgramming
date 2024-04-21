// P1073

#include <bits/stdc++.h>
using namespace std;

int a[100001];

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

int dis[300001], cnt[300001], n, m;
bitset<300001> vis;

void spfa() {
  memset(dis, 0x3f, sizeof(dis));
  memset(cnt, 0, sizeof(cnt));
  vis[1] = true, dis[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vis[u] = false;
    for (auto &ed : g[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v]++;
        if (!vis[v]) q.push(v), vis[v] = true;
      }
    }
  }
}

void add(int x, int y) {
  for (int i = 0; i < 3; i++)
    g[x + i * n].push_back({y + i * n, 0});
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  g.resize(n * 3 + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    // inverted
    g[i].push_back({i + n, a[i]});
    g[i + n].push_back({i + 2 * n, -a[i]});
  }
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    add(x, y);
    if (z == 2) add(y, x);
  }
  spfa();
  cout << -dis[3 * n];
  return 0;
}