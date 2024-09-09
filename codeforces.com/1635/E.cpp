// date: 2024-09-04 23:31:44
// tag: 二分图染色，dag偏序性质定边方向，拓扑排序输出

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> in(n + 1);
  std::vector<std::tuple<int, int, int>> ops(m + 1);
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    std::cin >> op >> x >> y;
    ops[i] = {op - 1, x, y};
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> col(n + 1, -1);
  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        if (col[v] == -1) {
          col[v] = col[u] ^ 1;
          self(self, v, u);
        } else if (col[v] == col[u]) {
          std::cout << "NO\n";
          exit(0);
        }
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (col[i] == -1) {
      col[i] = 1;
      dfs(dfs, i, 0);
    }
  }

  std::vector<std::vector<int>> G(n + 1);
  for (int i = 1; i <= m; i++) {
    auto [op, x, y] = ops[i];
    if (col[x] ^ op) {
      G[x].push_back(y);
      in[y]++;
    } else {
      G[y].push_back(x);
      in[x]++;
    }
  }

  std::queue<int> q;
  std::vector<int> vec;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      q.push(i);
    }
  }
  std::vector<int> x(n + 1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vec.push_back(u);
    x[u] = vec.size();
    for (int v : G[u]) {
      if (!--in[v]) {
        q.push(v);
      }
    }
  }
  if (vec.size() != n) {
    std::cout << "NO\n";
    return 0;
  }
  std::cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    std::cout << (col[i] ? "L" : "R") << ' ' << x[i] << '\n';
  }

  return 0;
}