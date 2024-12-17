#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

int n = 2e3;

void solve() {
  // int n = 2e3;
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << (rd() % (int)1e1) + 1 << ' ';
  }
  std::cout << '\n';
}

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  if (argc > 1) {
    n = atoi(argv[1]);
  }
  while (t--) {
    solve();
  }
  return 0;
}