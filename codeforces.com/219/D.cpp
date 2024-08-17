// date: 2024-08-13 12:54:21
// tag: 换根dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::set<int>> sg(n + 1);
  for (int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    sg[x].insert(y);
  }
  std::vector<int> f(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    f[u] += sg[u].count(p);
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        f[u] += f[v];
      }
    }
  };
  dfs(dfs, 1, 0);
  std::vector<int> ff(n + 1);
  auto dfs2 = [&](auto self, int u, int p, int prv) -> void {
    int sum = prv;
    for (int v : g[u]) {
      if (v != p) {
        sum += f[v];
      }
    }
    ff[u] = sum;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, sum - f[v] + sg[u].count(v));
      }
    }
  };
  dfs2(dfs2, 1, 0, 0);
  // for (int i = 1; i <= n; i++) {
  //   std::cout << f[i] << " \n"[i == n];
  // }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << ff[i] << " \n"[i == n];
  // }

  int mn = ff[1];
  for (int i = 2; i <= n; i++) {
    if (ff[i] < mn) {
      mn = ff[i];
    }
  }
  std::cout << mn << '\n';
  for (int i = 1; i <= n; i++) {
    if (mn == ff[i]) {
      std::cout << i << ' ';
    }
  }
  std::cout << "\n";

  return 0;
}