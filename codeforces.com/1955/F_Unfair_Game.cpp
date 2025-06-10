// date: 2025-04-06 23:50:18
// tag: 好吧，很多时候奇偶转换可以看看是不是O(1)的，哎思维

#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  std::cout << (d / 2) + (a / 2) + (b / 2) + (c / 2) + (a % 2 && b % 2 && c % 2) << '\n';
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