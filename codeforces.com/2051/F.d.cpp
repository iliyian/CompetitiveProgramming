#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int n = 1e3, m = rd() % n + 1, q = 1e3;
  std::cout << n << ' ' << m << ' ' << q << '\n';
  while (q--) {
    std::cout << rd() % n + 1 << ' ';
  }
  std::cout << "\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 100;
  // std::cin >> t;
  std::cout << t << '\n';
  while (t--) {
    solve();
  }
  return 0;
}