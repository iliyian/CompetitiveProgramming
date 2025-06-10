// date: 2025-04-16 23:11:07
// tag: 只能说相当神仙的一道题目。对位运算的认识达到出神入化简直。关键在于或的影响，而且进位可以令其最多只影响到下一位，因此可以考虑两位两位拆开，就很神仙。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int x = 0, y = 0;
  for (int i = 0; i < 30; i++) {
    x <<= 1, y <<= 1;
    x += i & 1 ^ 1, y += i & 1;
  }
  int ansx, ansy;
  std::cout << x << std::endl;
  std::cin >> ansx;
  std::cout << y << std::endl;
  std::cin >> ansy;
  std::cout << "!" << std::endl;
  int q, ans = 0;
  std::cin >> q;
  bool prv = 0;
  for (int i = 0; i < 30; i++) {
    int a, b;
    int res = (i % 2 == 0 ? ansx : ansy) >> i & 3;
    if (i) res = (res + 3) % 4;
    if (res == 0) {
      a = 0, b = 0;
    } else if (res == 1) {
      a = 1, b = 0;
    } else {
      a = 1, b = 1;
    }
    ans += (q >> i & 1 | a) << i;
    ans += (q >> i & 1 | b) << i;
  }
  std::cout << ans << std::endl;
}
// 1431655765
// 715827884

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}