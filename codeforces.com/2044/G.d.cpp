// date: 2024-12-16 22:55:13
// tag: 基环树森林dp

#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

int n = 2e5;

void solve() {
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << rd() % n + 1 << ' ';
  }
  std::cout << '\n';
}

signed main(signed argc, char **argv) {
  if (argc > 1) n = atoi(argv[1]);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  std::cout << t << '\n';
  while (t--) {
    solve();
  }
  return 0;
}