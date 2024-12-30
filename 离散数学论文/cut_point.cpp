#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> dfn(n + 1), low(n + 1), vis(n + 1), is_cutpoint(n + 1);
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
    int child = 0;
    for (int v : g[u]) {
      if (!vis[v]) {
        child++;
        self(self, v, u);
        low[u] = min(low[u], low[v]);
        if (u != p && low[v] >= dfn[u] && !is_cutpoint[u])
          // 至少有一个点无法通过子节点返回到u，所以u是割点
          // 并且u不是根节点
          is_cutpoint[u] = true;
      } else if (v != p)
        low[u] = min(low[u], dfn[v]);
    }
    // 当前节点为子树根节点，此时需要有两个不连通的子节点
    if (u == p && child >= 2) {
      is_cutpoint[u] = true;
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      tarjan(tarjan, i, i);
    }
  }
  std::cout << "共有";
  std::cout << std::count(is_cutpoint.begin(), is_cutpoint.end(), 1);
  std::cout << "个割点: ";
  for (int i = 1; i <= n; i++) {
    if (is_cutpoint[i]) {
      std::cout << i << ' ';
    }
  }
  return 0;
}