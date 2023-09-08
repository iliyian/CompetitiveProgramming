#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

array<int, 10001> a, dfn, low, s, in, pa, aa;
bitset<10001> ins;
int cnt = 0, tp = 0;

void tarjan(int u) {
  dfn[u] = low[u] = ++cnt;
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
    do {
      pa[s[tp]] = u;
      aa[u] += a[s[tp]];
      ins[s[tp]] = false;
    } while (s[tp--] != u);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i], pa[i] = i;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    in[v]++;
  }

  for (int i = 1; i <= n; i++)
    if (!dfn[i])
      tarjan(i);

  queue<int> q;
  vector<int> L;
  for (int i = 1; i <= n; i++) {
    if (pa[i] == i)
      q.push(i);
  }
  
  while (!q.empty()) {
    int u = q.front(); q.pop();
    L.push_back(u);
    for (int v : g[u])
      if (!--in[v])
        q.push(v);
  }

  return 0;
}