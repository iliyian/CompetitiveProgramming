#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int n = 2e5;
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << rd() % (int)1e9 + 1 << ' ';
  }
  std::cout << '\n';
}

signed main() {
  freopen("H.in", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cout << t << '\n';
  while (t--) {
    solve();
  }
  return 0;
}