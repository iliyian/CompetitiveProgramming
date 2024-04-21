// date: 2023/12/8
// wa#n...: memset写太多了啊艹
// 大批量数组初始化就应该一个for带过，

// 顺便这题有一个新的tarjan模板？？？

#include <bits/stdc++.h>
#define N 200005
// #define int long long
using namespace std;

int a[N], dfn[N], low[N], scc[N], sz[N], dfncnt = 0, tp = 0, sc = 0;
vector<vector<int>> g;
stack<int> s;

void tarjan(int u) {
  dfn[u] = low[u] = ++dfncnt;
  s.push(u);
  for (auto v : g[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (!scc[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++sc;
    while (1) {
      int x = s.top(); s.pop();
      scc[x] = sc;
      sz[sc]++;
      if (x == u) break;
    }
  }
}

vector<vector<int>> sccg;
pair<int, long long> f[N];
long long scca[N];

void solve() {
  int n, m;
  cin >> n >> m;

  g.assign(n + 1, vector<int>());
  sccg.assign(n + 1, vector<int>());
  sc = 0;
  for (int i = 1; i <= n; i++)
    dfn[i] = low[i] = scc[i] = scca[i] = sz[i] = 0, f[i] = {0, 0};
  // memset(dfn, 0, sizeof(dfn));
  // memset(low, 0, sizeof(low));
  // memset(scc, 0, sizeof(scc));
  // memset(scca, 0, sizeof(scca));
  // memset(f, 0, sizeof(f));
  // memset(sz, 0, sizeof(sz));

  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i);

  for (int i = 1; i <= n; i++) {
    scca[scc[i]] += a[i];
    for (auto v : g[i])
      if (scc[i] != scc[v])
        sccg[scc[i]].push_back(scc[v]);
  }

  for (int i = 1; i <= sc; i++) {
    auto now = pair{sz[i], -scca[i]};
    f[i] = now;
    for (auto v : sccg[i])
      f[i] = max(f[i], pair{now.first + f[v].first, now.second + f[v].second});
  }

  auto ans = f[1];
  for (int i = 1; i <= sc; i++)
    ans = max(ans, f[i]);
  cout << ans.first << ' ' << -ans.second << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}