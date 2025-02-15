#include <bits/stdc++.h>
#define N 5005
using namespace std;

vector<vector<int>> g;
int cnt = 0, tp = 0, scc_cnt = 0, s[N], scc[N], dfn[N], low[N], bridgeCnt = 0;
int pa[N];
bitset<N> ins, isBridge, vis, ed[N];

int bcc_cnt = 0, bcc[N], in[N];

void tarjan(int u, int prv) {
  low[u] = dfn[u] = ++cnt;
  s[++tp] = u;
  ins[u] = true;
  pa[u] = prv;
  for (int v : g[u]) {
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u])
      // 然后，pa[v]和v才是桥，不然没法表示边
        isBridge[v] = true, bridgeCnt++;
      // 判断无向图桥的这个 else if 还有第二个条件，不知道为啥......
    } else if (v != prv) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    ++scc_cnt;
    while (true) {
      int x = s[tp--];
      ins[x] = false;
      scc[x] = scc_cnt;
      if (x == u) break;
    }
  }
}

void dfs(int u) {
  bcc[u] = bcc_cnt;
  for (int v : g[u]) {
    if (bcc[v] || (isBridge[v] && pa[v] == u) || (isBridge[u] && pa[u] == v))
      continue;
    dfs(v);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n * 2 + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (ed[u][v] || ed[v][u]) continue;
    ed[u][v] = ed[v][u] = true;
    g[u].push_back(v), g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i, 0);

  for (int i = 1; i <= n; i++)
    if (!bcc[i]) {
      bcc_cnt++;
      dfs(i);
    }

  for (int u = 1; u <= n; u++)
    for (int v : g[u]) {
      int bu = bcc[u], bv = bcc[v];
      if (bu != bv)
        in[bu]++;
    }
  
  int leafCnt = 0;
  for (int i = 1; i <= n; i++) {
    std::cerr << bcc[i] << " \n"[i == n];
  }
  for (int i = 1; i <= bcc_cnt; i++)
    leafCnt += in[i] == 1;
  std::cout << leafCnt << '\n';
  
  cout << (leafCnt + 1) / 2 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
//   freopen("main.in", "r", stdin);
//   freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}