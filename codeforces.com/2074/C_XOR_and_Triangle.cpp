#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  if (__builtin_popcountll(n) == 1) {
    std::cout << -1 << '\n';
    return;
  }
  bool f = false, g = false;
  int ans = n;
  for (int i = 30; i >= 0; i--) {
    if (n >> i & 1) {
      if (!f) {
        f = true;
        ans ^= 1 << i;          
      }
    } else if (f) {
      g = true;
      ans ^= 1 << i;
      break;
    }
  }
  if (!g) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << ans << '\n';
  // std::cout << ans << ' ' << n << ' ' << (ans ^ n) << '\n';
  // for (int i = 0;; i++) {
  //   if (((1 << (i + 1)) > n)) {
  //     ans ^= 1 << i;
  //     break;
  //   }
  //   if (n >> i & 1) {
  //     if (!f1) {
  //       f1 = true;
  //       ans ^= 1 << i;
  //     }
  //   } else {
  //     if (!f0) {
  //       f0 = true;
  //       ans ^= 1 << i;
  //     }
  //   }
  // }
  // if (f1 && f0) {
  //   std::cout << ans << '\n';
  //   assert((ans ^ n) != ans - n);
  //   assert((ans ^ n) != ans + n);
  //   // assert(ans < n);
  // } else {
  //   std::cout << -1 << '\n';
  // }
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