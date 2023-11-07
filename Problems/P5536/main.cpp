// wa#0: 可能是数组清理不到位
// wa#1: 缺乏全部推倒重来的勇气
// re#2: N改小避免gdb的max-value-size后忘记改回去就提交了
// wa#3: u和prev写反了，即公式中的参数写反了

#include <bits/stdc++.h>
#define N 100001
using namespace std;

vector<vector<int>> g;
int dis[N], pa[N], maxr = -1, r, maxd[N], ans[N];

void dfs(int u, int prev) {
  for (int v : g[u]) {
    if (v == prev) continue;
    pa[v] = u;
    dis[v] = dis[u] + 1;
    if (dis[v] > maxr) {
      maxr = dis[v];
      r = v;
    }
    dfs(v, u);
  }
}

void dfs2(int u, int prev) {
  maxd[u] = dis[u] = dis[prev] + 1;
  for (int v : g[u]) {
    if (v == prev) continue;
    dfs2(v, u);
    maxd[u] = max(maxd[u], maxd[v]);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  
  int n, k;
  cin >> n >> k;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);

  memset(pa, 0, sizeof(pa));
  memset(dis, 0, sizeof(dis));
  dis[r] = 0, maxr = -1;
  dfs(r, 0);

  int mid = r;
  for (int i = 0; i < maxr / 2; i++)
    mid = pa[mid];
  memset(dis, 0, sizeof(dis));

  dfs2(mid, 0);

  for (int i = 1; i <= n; i++)
    ans[i] = maxd[i] - dis[i];
  sort(ans + 1, ans + 1 + n);

  cout << ans[n - k] + 1;
  return 0;
}