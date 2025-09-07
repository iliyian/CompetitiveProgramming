#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int t = 1;
  // std::cout << t << '\n';
  while (t--) {
    int n = 10000, w = 1;
    std::cout << n << '\n';
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
      // std::cout << (rd() % 4 == 0 ? 0 : 1) << ' ';
      std::cout << ((rd() % (w + 1))) << ' ';
      // std::cout << 1 << ' ';
    }
    std::cout << '\n';
    for (int i = 2; i <= n; i++) {
      // int x = rd() % (i - 1) + 1, y = i;
      // int x = 1, y = i;
      int x = i - 1, y = i;
      // g[rd() % ()]
      g[x].push_back(y);
      std::cout << x << ' ' << y << '\n';
      // std::cout << rd() % (i - 1) + 1 << ' ' << i << '\n';
      // std::cout << i - 1 << ' ' << i << '\n';
      // std::cout << 1 << ' ' << i << '\n';
    }
    int m = 0;
    std::cout << m << '\n';
    for (int i = 1; i <= m; i++) {
      int x, y;
      while (1) {
        x = rd() % n + 1, y = rd() % n + 1;
        bool f = false;
        auto dfs = [&](auto self, int u) -> void {
          for (int v : g[u]) {
            if (v == y) {
              f = true;
              break;
            }
            if (f) {
              return;
            }
          }
          if (f) {
            return;
          }
        };
        dfs(dfs, x);
        if (f) {
          break;
        }
      }
      std::cout << y << ' ' << x << '\n';
    }
    // std::cout << '\n';
  }

  return 0;
}