#include <bits/stdc++.h>
#include <random>
#define int long long

std::mt19937 rd(std::random_device{}());


void solve() {
  int n;
  std::cin >> n;
  std::cout << n << '\n';
  for (int i = 2; i <= n; i++) {
    std::cout << rd() % (i - 1) + 1 << ' ' << i << '\n';
  }
  // std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cout << t << '\n';
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}