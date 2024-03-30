// date: 2024-03-29 10:58:47
// tag: 缩点，dfs
// tle#01: 写成简单的搜索又难以剪枝
// tle#02: 写成简单的搜索又难以剪枝

// 图上的环基本上都要缩点解决，不然你怎么剪？

#include <bits/stdc++.h>
// #define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
  }

  int dfncnt = 0, scc_cnt = 0;
  vector<int> dfn(n + 1), low(n + 1), scc(n + 1), siz(n + 1);
  vector<bool> ins(n + 1);
  stack<int> st;
  auto tarjan = [&](auto self, int u) -> void {
    st.push(u);
    dfn[u] = low[u] = ++dfncnt;
    ins[u] = true;
    for (int v : g[u]) {
      if (!dfn[v]) {
        self(self, v);
        low[u] = min(low[u], low[v]);
      } else if (ins[v]) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (dfn[u] == low[u]) {
      ++scc_cnt;
      while (true) {
        int x = st.top(); st.pop();
        ins[x] = false;
        scc[x] = scc_cnt;
        siz[scc_cnt]++;
        if (x == u) break;
      }
    }
  };

  tarjan(tarjan, 1);

  vector<vector<int>> sg(scc_cnt + 1);
  vector<bool> vis(n + 1), sect(n + 1), ring(n + 1);
  for (int u = 1; u <= n; u++) {
    for (int v : g[u]) {
      if (v == u) ring[scc[u]] = true;
      if (scc[u] != scc[v]) {
        sg[scc[u]].push_back(scc[v]);
      }
    }
  }

  auto dfs = [&](auto self, int u) -> void {
    for (int v : sg[u]) {
      if (!vis[v]) {
        vis[v] = true;
        self(self, v);
      } else {
        sect[v] = true;
      }
    }
  };
  vis[scc[1]] = true;
  dfs(dfs, scc[1]);

  for (int i = 1; i <= scc_cnt; i++) {
    if (siz[i] >= 2) {
      ring[i] = true;
    }
  }

  auto dfs2 = [&](auto self, int u, vector<bool>& which) -> void {
    which[u] = true;
    for (int v : sg[u]) {
      if (!which[v]) {
        self(self, v, which);
      }
    }
  };
  for (int i = 1; i <= scc_cnt; i++) {
    if (ring[i]) {
      dfs2(dfs2, i, ring);
    }
  }
  for (int i = 1; i <= scc_cnt; i++) {
    if (sect[i]) {
      dfs2(dfs2, i, sect);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      cout << 0 << ' ';
    } else if (ring[scc[i]]) {
      cout << -1 << ' ';
    } else if (sect[scc[i]]) {
      cout << 2 << ' ';
    } else {
      cout << 1 << ' ';
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}