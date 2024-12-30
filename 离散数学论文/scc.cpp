#include <bits/stdc++.h>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
  }
  std::stack<int> s;
  std::vector<int> ins(n + 1), scc(n + 1), dfn(n + 1), low(n + 1);
  std::vector<std::vector<int>> sg(n + 1);
  int cnt = 0, scc_cnt = 0;
  auto tarjan = [&](this auto &&self, int u) -> void {
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    ins[u] = 1;
    for (int v : g[u]) {
      if (!dfn[v]) {
        self(v);
        low[u] = std::min(low[u], low[v]);
      } else if (ins[v]) {
        low[u] = std::min(low[u], dfn[v]);
      }
    }
    if (dfn[u] == low[u]) {
      ++scc_cnt;
      while (true) {
        int x = s.top(); s.pop();
        ins[x] = 0;
        scc[x] = scc_cnt;
        sg[scc_cnt].push_back(x);
        if (x == u) break;
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  for (int i = 1; i <= scc_cnt; i++) {
    std::sort(sg[i].begin(), sg[i].end());
    std::cout << "SCC " << i << ": ";
    for (auto j : sg[i]) {
      std::cout << j << ' ';
    }
    std::cout << '\n';
  }
}