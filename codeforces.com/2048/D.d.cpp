#include <algorithm>
#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int n = 3e5, m = 3e5;
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << rd() % (int)1e9 << " \n"[i == n];
  }
  for (int i = 1; i <= m; i++) {
    std::cout << rd() % (int)1e9 << " \n"[i == m];
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  std::cout << t << '\n';
  while (t--) {
    solve();
  }
  return 0;
}
