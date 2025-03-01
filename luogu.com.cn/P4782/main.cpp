// date: 2024/01/29 15:36:17
// tag: 带方案输出的2-sat模板题，顺便复习tarjan缩点

#include <bits/stdc++.h>
#define N 2000005
using namespace std;

vector<vector<int>> g;
int low[N], dfn[N], cnt = 0, scc[N], s[N], tp = 0, scc_cnt = 0;
bitset<N> ins;

void tarjan(int u) {
  dfn[u] = low[u] = ++cnt;
  s[++tp] = u;
  ins[u] = true;
  for (int v : g[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (ins[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    ++scc_cnt;
    while (true) {
      int x = s[tp--];
      scc[x] = scc_cnt;
      ins[x] = false;
      if (x == u) break;
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n * 2 + 1);
  for (int i = 0; i < m; i++) {
    int x, y, a, b;
    cin >> x >> a >> y >> b;
    g[x + (!a) * n].push_back(y + b * n);
    g[y + (!b) * n].push_back(x + a * n);
  }
  for (int i = 1; i <= n * 2; i++)
    if (!dfn[i])
      tarjan(i);
  for (int i = 1; i <= n; i++) {
    if (scc[i] == scc[i + n]) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  cout << "POSSIBLE\n";
  for (int i = 1; i <= n; i++)
    // 这里不能反过来
    cout << (scc[i + n] < scc[i]) << " \n"[i == n];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}