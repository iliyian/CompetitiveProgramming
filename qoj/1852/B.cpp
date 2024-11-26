#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  if (std::gcd(n, m) != 1) {
    std::cout << "No\n";
    return;
  }
  std::cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    std::cout << (n + (i - 1) * m + n * m) % (n * m) << ' ';
  }
  std::cout << '\n';
  for (int i = 1; i <= m; i++) {
    std::cout << (m + (i - 1) * n + m * n) % (m * n) << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}