// date: 2025-09-29 22:51:01
// tag: ??????????????????????
// 为什么当年我做不出来？？？
// 好吧至少确实有进步了

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
    std::cout << ((i - 1) * m + 1) % (n * m) << ' ';
  }
  std::cout << '\n';
  for (int i = 1; i <= m; i++) {
    std::cout << ((i - 1) * n + 1) % (n * m) << ' ';
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