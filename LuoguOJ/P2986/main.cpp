// wa#01: 正无穷在long long下没有设置成0x3f3f3f3f3f3f3f3f，
//        应该是这个原因，或者是答案在递归中的更新位置错误

#include <bits/stdc++.h>
#define N 1000001
#define int long long
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

int a[N], f[N], sz[N], sum[N], ans = 0x3f3f3f3f3f3f3f3f, cnt = 0;

void dfs1(int u, int prev) {
  sz[u] = a[u];
  for (auto &ed : g[u]) {
    int v = ed.v, w = ed.w;
    if (v == prev) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    f[u] += f[v] + sz[v] * w;
  }
}

void dfs2(int u, int prev) {
  ans = min(ans, sum[u]);
  for (auto &ed : g[u]) {
    int v = ed.v, w = ed.w;
    if (v == prev) continue;
    sum[v] = sum[u] - sz[v] * w + (cnt - sz[v]) * w;
    dfs2(v, u);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i], cnt += a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs1(1, 0);

  // origin
  sum[1] = f[1];
  dfs2(1, 0);
  cout << ans;
  return 0;
}