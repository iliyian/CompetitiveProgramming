#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, p;
  std::cin >> n >> k >> p;
  if (k < 0 && -n * p > k || k > 0 && n * p < k) {
    std::cout << -1 << "\n";
    return;
  }
  if (k == 0) {
    std::cout << 0 << '\n';
    return;
  }
  k = std::abs(k);
  std::cout << (k + p - 1) / p << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}