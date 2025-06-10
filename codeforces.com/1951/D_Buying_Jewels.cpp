// date: 2025-05-11 18:28:00
// tag: 什么脑筋急转弯的数论构造

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  if (n % 2 == 1 && k == n / 2 + 1) {
    std::cout << "YES\n";
    std::cout << 2 << '\n';
    std::cout << n / 2 + 1 << ' ' << 1 << '\n';
    return;
  }
  if (k == n) {
    std::cout << "YES\n";
    std::cout << 1 << '\n';
    std::cout << 1 << '\n';
    return;
  }
  if (k > n / 2) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  std::cout << 2 << '\n';
  std::cout << n - k + 1 << ' ' << 1 << '\n';
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