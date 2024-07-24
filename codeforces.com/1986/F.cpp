#include <bits/stdc++.h>
#define int long long
#define N ((int)1e5)
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> low(n + 1), dfn(n + 1), pa(n + 1), scc(n + 1);
  vector<int> s(n + 1);
  bitset<N + 1> ins, isBridge;
  int cnt = 0, tp = 0, bridgeCnt, scc_cnt;
  auto tarjan = [&](auto self, int u, int prv) -> void {
    low[u] = dfn[u] = ++cnt;
    s[++tp] = u;
    ins[u] = true;
    pa[u] = prv;
    for (int v : g[u]) {
      if (!dfn[v]) {
        self(self, v, u);
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
  };
  tarjan(tarjan, 1, 0);

  bitset<N + 1> vis;
  vector<int> siz(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    vis[u] = true;
    for (int v : g[u]) {
      if (v != p && !vis[v]) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
  };
  dfs(dfs, 1, 0);

  int tot = n * (n - 1) / 2;
  int ans = tot;
  vis.reset();
  auto dfs2 = [&](auto self, int u) -> void {
    vis[u] = true;
    for (int v : g[u]) {
      if (v != pa[u] && !vis[v]) {
        if (isBridge[v]) {
          ans = min(ans, tot - (n - siz[v]) * siz[v]);

        }
        self(self, v);
      }
    }
  };
  dfs2(dfs2, 1);
  cout << ans << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}