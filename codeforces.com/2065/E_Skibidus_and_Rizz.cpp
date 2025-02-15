#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  if (std::abs(n - m) > k || n < k && m < k) {
    std::cout << -1 << '\n';
    return;
  }
  if (n > m) {
    for (int i = 1; i <= k; i++) {
      std::cout << 0;
      n--;
    }
    while (n && m) {
      std::cout << "10";
      n--, m--;
    }
    while (m) std::cout << 1, m--;
    while (n) std::cout << 0, n--;
  } else {
    for (int i = 1; i <= k; i++) {
      std::cout << 1;
      m--;
    }
    while (n && m) {
      std::cout << "01";
      n--, m--;
    }
    while (n) std::cout << 0, n--;
    while (m) std::cout << 1, m--;
  }
  std::cout << '\n';
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