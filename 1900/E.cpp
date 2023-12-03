#include <bits/stdc++.h>
#define N 200005
// #define int long long
using namespace std;

int a[N], dfn[N], low[N], scc[N], s[N], sz[N], dfncnt = 0, tp = 0, sc = 0;
bitset<N> ins;
vector<vector<int>> g;

void tarjan(int u) {
  dfn[u] = low[u] = ++dfncnt;
  s[++tp] = u;
  ins[u] = true;
  for (auto v : g[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (ins[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++sc;
    while (s[tp] != u) {
      scc[s[tp]] = sc;
      sz[sc]++;
      ins[s[tp--]] = false;
    }
    scc[s[tp]] = sc;
    sz[sc]++;
    ins[s[tp--]] = false;
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
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(scc, 0, sizeof(scc));
  memset(s, 0, sizeof(s));
  memset(scca, 0, sizeof(scca));
  memset(f, 0, sizeof(f));
  memset(sz, 0, sizeof(sz));
  ins.reset();

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