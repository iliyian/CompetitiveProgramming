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

void solve() {
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char ch;
      std::cin >> ch;
      if (ch == '1') {
        g[i].push_back(j);
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) {
      tarjan(i, 0);
    }
  std::cout << (bridgeCnt + 2) / 2 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}