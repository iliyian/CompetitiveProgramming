#include <bits/stdc++.h>
#include <random>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int n = 1e5, q = 1e5;
  int N = 1e5;
  std::cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << std::max(1ll, std::min(N, (int)std::abs(std::normal_distribution<>{N / 2.0, N / 10.0}(rd)))) << ' ';
  }
  std::cout << '\n';
  std::cout << q << '\n';
  while (q--) {
    int l = rd() % n + 1, r = rd() % n + 1;
    while (l == r) {
      l = rd() % n + 1, r = rd() % n + 1;
    }
    if (l > r) std::swap(l, r);
    std::cout << l << ' ' << r << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}