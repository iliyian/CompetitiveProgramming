#include <bits/stdc++.h>
#define int long long

using u32 = unsigned;
using i64 = long long;

void solve() {
  int n;
  std::cin >> n;
  i64 a = 1, b = 1;
  u32 ans = 0;
  for (int i = 1; i <= n; i++) {
    a *= 114514, a %= 998244353;
    b *= 1919810, b %= (int)1e9 + 7;
    u32 v = ((u32)a * (u32)b) ^ 1777777777;
    u32 w = v + 2333333333;
    u32 x = (w ^ (w >> 15)) * 1145141145;
    u32 y = (x ^ (x >> 14)) * 1919810191;
    u32 z = y ^ (y >> 16);
    ans += z;
  }
  std::cout << ans << '\n';
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