// ++tp 保证 tp 真的指向 top
// 顺便 do while 可以取代两次同样代码块

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

int cnt = 0, tp = 0, scc = 0, low[10001], dfn[10001], s[10001], sc[10001], sz[10001];
bitset<10001> ins;

void tarjan(int u) {
  low[u] = dfn[u] = ++cnt;
  ins[u] = true;
  s[++tp] = u;
  for (int v : g[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (ins[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++scc;
    do {
      ins[s[tp]] = false;
      sc[s[tp]] = scc;
      sz[scc]++;
    } while (s[tp--] != u);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  memset(dfn, 0, sizeof(dfn));

  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i);

  int ans = 0;
  for (int i = 1; i <= scc; i++) {
    ans += sz[i] > 1;
  }
  cout << ans;
  return 0;
}