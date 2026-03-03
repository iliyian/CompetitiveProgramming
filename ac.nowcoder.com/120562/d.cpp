#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("d.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int n = 50000;
  std::cout << n << '\n';
  std::vector<int> p(n);
  std::ranges::iota(p, 0);
  std::shuffle(p.begin(), p.end(), rd);
  for (int i = 0; i < n; i++) {
    std::cout << p[i] << ' ';
  }
  std::cout << '\n';
  std::vector<std::vector<int>> g(n);
  for (int i = 2; i <= n; i++) {
    int x = rd() % (i - 1) + 1, y = i;
    std::cout << x << ' ' << y << '\n';
    x--, y--;
    // g[x].push_back(y);
    // g[y].push_back(x);
  }
  // std::vector<int> dfn(n);
  // int tot = 0;
  // auto dfs = [&](auto self, int u, int p) -> void {
  //   dfn[u] = tot++;
  //   for (int v : g[u]) {
  //     if (v != p) {
  //       self(self, v, u);
  //     }
  //   }
  // };
  // dfs(dfs, 1, 0);
  // for ()

  return 0;
}