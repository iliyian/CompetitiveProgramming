// date: 2023/12/24 14:48:00
// tag: 又双叒叕是树的直径和强连通分量

#include <bits/stdc++.h>
#define N 300005
using namespace std;

vector<vector<int>> g, sg;
int dfncnt = 0, scc_no[N], dfn[N], sc_cnt = 0, dep[N], low[N];
stack<int> st;

void tarjan(int u, int prev) {
  dfn[u] = low[u] = ++dfncnt;
  st.push(u);
  for (int v : g[u]) {
    if (v == prev) continue;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (!scc_no[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    ++sc_cnt;
    while (true) {
      int x = st.top(); st.pop();
      scc_no[x] = sc_cnt;
      if (x == u) break;
    }
  }
}

int maxdep = -1, c = -1;
bitset<N> vis;

void dfs(int u, int prev) {
  dep[u] = dep[prev] + 1;
  if (vis[u]) return;
  vis[u] = true;
  if (dep[u] > maxdep) {
    maxdep = dep[u];
    c = u;
  }
  for (int v : sg[u]) {
    if (v != prev)
      dfs(v, u);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i, 0);
  sg.resize(sc_cnt + 1);
  for (int i = 1; i <= n; i++)
    for (int v : g[i])
      if (scc_no[i] != scc_no[v])
        sg[scc_no[i]].push_back(scc_no[v]);
  vis.reset();
  dfs(1, 0);
  
  int ori = c;
  maxdep = -1;
  vis.reset();
  dfs(ori, 0);

  cout << maxdep - 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  // int _; cin >> _;
  int _  = 1;
  while (_--) solve();
}