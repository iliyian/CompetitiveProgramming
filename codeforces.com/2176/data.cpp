#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("data.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int t = 1;
  std::cout << t << '\n';
  std::vector<int> f(70);
  f[0] = f[1] = 1;
  for (int i = 2; i < 70; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  while (t--) {
    int n = 500, w = 2e5;
    int m = n * (n - 1);
    std::cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) {
      // std::cout << rd() % w + 1 << ' ';
      std::cout << f[rd() % 70] << ' ';
    }
    std::cout << '\n';
    std::set<std::pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        std::cout << i << ' ' << j << '\n';
      }
    }
    // for (int i = 1; i <= m; i++) {
    //   int x = rd() % n + 1, y = rd() % n + 1;
    //   while (x == y || s.count({x, y})) {
    //     x = rd() % n + 1, y = rd() % n + 1;
    //   }
    //   std::cout << x << ' ' << y << '\n';
    //   s.insert({x, y});
    // }
  }

  return 0;
}