// date: 2023/12/5
// tag: tree_diameter
// wa#01: 搞错了B点，其不一定在直径上

#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

struct Edge {
  int v, w;
};

vector<vector<Edge>> g;

int d = 0, dis[N], c = -1, disa[N], disc[N];

void dfs1(int u, int prev) {
  for (auto &[v, w] : g[u]) {
    if (v == prev) continue;
    dis[v] = dis[u] + w;
    // 如果第一次dfs就到了某直径一端，避免第二次dfs更新不了c
    if (dis[v] >= d) d = dis[v], c = v;
    dfs1(v, u);
  }
}

void dfs2(int u, int prev, int disx[]) {
  for (auto &[v, w] : g[u]) {
    if (v == prev) continue;
    disx[v] = disx[u] + w;
    dfs2(v, u, disx);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs1(1, 0);
  int a = c;
  dis[c] = 0;
  dfs1(c, 0);

  dfs2(a, 0, disa), dfs2(c, 0, disc);

  // int ans = 0x3f3f3f3f3f3f3f3f;
  int ans = -1;
  for (int i = 1; i <= n; i++)
    ans = max(ans, min(disa[i], disc[i]));
  cout << d + ans;
  return 0;
}