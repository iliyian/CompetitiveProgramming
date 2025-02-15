// date: 2025-01-31 16:57:48
// tag: 神仙妙妙位运算题
// 首先考虑 x-n<=x^n=x%n<n,x<n*2
// x<n -> x%n=x=x^n -> n=0 -> n<=x<n*2
// x%n=x-n=x^n -> 
// 考虑异或不存在进位，所以对于n中所有为0的位，x为1或0（1^0=1-0&1^1=1-1），为1的位，x只能为1（为0的话必然导致借位）
// 真他妈的妙妙题

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  int ans = 0;
  k--;
  for (int i = 0; i <= 62; i++) {
    if ((1ll << i) > n) break;
    if (n >> i & 1) {
      ans ^= 1ll << i;
    } else {
      if (k) {
        ans ^= (k & 1) << i;
        k >>= 1;
      }
    }
  }
  if (k) {
    std::cout << -1 << '\n';
  } else {
    std::cout << ans << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int n = 1; n <= 100; n++) {
  //   std::cerr << n << ": ";
  //   for (int i = 1; i <= 100000; i++) {
  //     if ((i ^ n) == i % n) {
  //       std::cerr << i << ' ';
  //     }
  //   }
  //   std::cerr << '\n';
  // }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}