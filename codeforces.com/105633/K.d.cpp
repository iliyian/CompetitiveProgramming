#include <bits/stdc++.h>
#include <random>
#define int long long

std::mt19937 rd(std::random_device{}());

int n = 2e5, m = 20;

void solve() {
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cout << "NY"[std::uniform_real_distribution<>{0, 1}(rd) >= 0.33];
    }
    std::cout << '\n';
  }
}

int32_t main(signed argc, char **argv) {
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