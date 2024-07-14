// date: 2024-07-08 19:49:00
// tag: 树的直径

#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> dep(n + 1);
  int c = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    if (dep[u] > dep[c]) {
      c = u;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);

  int e1 = c;
  dep[c] = 0;
  dfs(dfs, c, 0);
  int d = dep[c];
  int e2 = c;

  std::vector<int> dis1(n + 1, -1), dis2(n + 1, -1);

  auto dfs2 = [&](auto self, int u, int p, std::vector<int> &dis) -> void {
    dis[u] = dis[p] + 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, dis);
      }
    }
  };
  dfs2(dfs2, e1, 0, dis1);
  dfs2(dfs2, e2, 0, dis2);
  std::vector<int> ans(n + 2);
  for (int i = 1; i <= n; i++) {
    int maxd = std::max(dis1[i], dis2[i]);
    ans[maxd + 1]++, ans[n + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    ans[i] += ans[i - 1];
    std::cout << std::min(ans[i] + 1, n) << " \n"[i == n];
  }

  return 0;
}