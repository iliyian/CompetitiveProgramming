// date: 2024/01/30 19:17:54
// tag: wa很多次，最后发现要特判重边，两个点之间只能有一条直接连接的边
// 双连通分量模板，但我写的应该不够好，例如scc数组完全没用...
// 关键在于判断桥的算法，即low[v]>dfn[u],则(pa[v], v)为桥
// 还有最后的dfs就是简单的遍历了

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
    } else if (ins[v] && v != prv) {
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
  for (int i = 1; i <= bcc_cnt; i++)
    leafCnt += in[i] == 1;
  
  cout << (leafCnt + 1) / 2 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}