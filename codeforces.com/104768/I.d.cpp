#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

int n = 100, m = 100;

void solve() {
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << rd() % m + 1 << ' ';
  }
  std::cout << '\n';
}

signed main(signed argc, char **argv) {
  freopen("I.in", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cout << t << '\n';
  if (argc > 1) n = atoi(argv[1]);
  if (argc > 2) m = atoi(argv[2]);
  while (t--) {
    solve();
  }
  return 0;
}