#include <bits/stdc++.h>
#define int long long
// using namespace std;

signed main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "w", stdout);

  std::mt19937 rd(std::random_device{}());

  int N = 1e5, M = 2e5, K = 1e5;
  int n = N, m = M, k = K;

  if (argc > 1) n = atoi(argv[1]);
  if (argc > 2) m = atoi(argv[2]);
  if (argc > 3) k = atoi(argv[3]);

  std::cout << n << ' ' << m << ' ' << k << '\n';
  for (int i = 1; i <= m; i++) {
    int x = std::uniform_int_distribution<int>{1, n}(rd);
    int y = std::uniform_int_distribution<int>{1, n}(rd);
    while (y == x) {
      y = std::uniform_int_distribution<int>{1, n}(rd);
    }
    int r = std::uniform_int_distribution<int>{1, k}(rd);
    int l = std::uniform_int_distribution<int>{0, r - 1}(rd);
    std::cout << x << ' ' << y << ' ' << l << ' ' << r << '\n';
  }

  return 0;
}