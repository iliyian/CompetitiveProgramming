#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> dfn(n + 1), low(n + 1), vis(n + 1), is_cutedge(n + 1), pa(n + 1);
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  auto tarjan = [&](auto self, int u, int p) -> void {
    dfn[u] = low[u] = ++cnt;
    vis[u] = true;
    pa[u] = p;
    for (int v : g[u]) {
      if (!vis[v]) {
        self(self, v, u);
        low[u] = std::min(low[u], low[v]);
        if (low[v] > dfn[u]) {
          is_cutedge[v] = 1;
        }
      } else if (v != p)
        low[u] = min(low[u], dfn[v]);
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      tarjan(tarjan, i, i);
    }
  }
  std::cout << "共有";
  std::cout << std::count(is_cutedge.begin(), is_cutedge.end(), 1);
  std::cout << "条割边: \n";
  for (int i = 1; i <= n; i++) {
    if (is_cutedge[i]) {
      std::cout << i << ' ' << pa[i] << '\n';
    }
  }
  return 0;
}