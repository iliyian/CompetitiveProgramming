#include <bits/stdc++.h>
// #define int long long

std::mt19937 rd(std::random_device{}());

int n = 1000, m = 1e6;

void solve() {
  int sx = std::uniform_int_distribution<>{-m, m}(rd);
  int sy = std::uniform_int_distribution<>{-m, m}(rd);
  std::cout << sx << ' ' << sy << '\n' << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << std::uniform_int_distribution<>{-m, m}(rd) << ' ';
    std::cout << std::uniform_int_distribution<>{-m, m}(rd) << ' ';
    std::cout << std::uniform_int_distribution<>{0, m * 2}(rd) << ' ';
    std::cout << '\n';
  }
}

signed main(signed argc, char **argv) {
  if (argc > 1) n = atoi(argv[1]);
  if (argc > 2) m = atoi(argv[2]);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}