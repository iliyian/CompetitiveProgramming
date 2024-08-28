// date: 2024-08-24 12:54:37
// tag: 并查集维护时间信息，倍增查询节点是否在链上，离线

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> pa(21, std::vector<int>(n + 1));
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::pair<int, int>> doc = {{}};
  std::vector<std::pair<int, int>> ask;
  std::vector<int> id(n + 1), siz(n + 1, 1);
  std::iota(id.begin(), id.end(), 0);
  auto find = [&](auto self, int x) -> int {return x == id[x] ? x : id[x] = self(self, id[x]);};
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x >> y;
      id[x] = y;
      pa[0][x] = y;
      g[y].push_back(x);
    } else if (op == 2) {
      std::cin >> x;
      doc.push_back({x, find(find, x)});
    } else {
      std::cin >> x >> y;
      ask.push_back({x, y});
    }
  }
  std::vector<int> dep(n + 1);
  auto dfs = [&](auto self, int u) -> void {
    for (int i = 1; i <= 20; i++) {
      pa[i][u] = pa[i - 1][pa[i - 1][u]];
    }
    for (int v : g[u]) {
      dep[v] = dep[u] + 1;
      self(self, v);
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!pa[0][i]) {
      dep[i] = 1;
      dfs(dfs, i);
    }
  }
  for (auto &[x, y] : ask) {
    auto [u, mx] = doc[y];
    for (int i = 20; i >= 0; i--) {
      if (dep[pa[i][u]] >= std::max(dep[mx], dep[x])) {
        u = pa[i][u];
      }
    }
    std::cout << (u == x ? "YES" : "NO") << '\n';
  }

  return 0;
}