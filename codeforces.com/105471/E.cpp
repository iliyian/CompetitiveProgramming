#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
  }
  std::vector<int> dfn(n + 1), low(n + 1), scc(n + 1);
  std::stack<int> s;
  std::vector<int> ins;
  int cnt = 0, scc_cnt = 0;
  auto tarjan = [&](auto self, int u) -> void {
    s.push(u);
    ins[u] = true;
    low[u] = dfn[u] = ++cnt;
    for (int v = 1; v <= n; v++) {
      if (a[u][v]) {
        if (!dfn[v]) {
          self(self, v);
          low[u] = std::min(low[u], low[v]);
        } else if (low[v]) {
          low[u] = std::min(low[u], dfn[v]);
        }
      }
    }
    if (low[u] == dfn[u]) {
      ++scc_cnt;
      while (true) {
        int x = s.top(); s.pop();
        scc[x] = scc_cnt;
        ins[x] = false;
        if (x == u) break;
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(tarjan, i);
    }
  }
  for (int i = 1; i <= n; i++) {
    
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}