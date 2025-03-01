#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x;
  std::cin >> n >> x;
  int cur = 0;
  auto check = [&](int y) {
    for (int i = 30; i >= 0; i--) {
      if (x >> i & 1 ^ 1 && y >> i & 1) {
        return false;
      }
    }
    return true;
  };
  for (int i = 0; i < n - 1; i++) {
    std::cout << (check(i) ? i : 0) << ' ';
    cur |= i;
  }
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    if (x >> i & 1 && cur >> i & 1 ^ 1) {
      ans |= 1 << i;
    }
  }
  // bool f = true;
  // for (int i = 30; i >= 0; i--) {
  //   if (x >> i & 1 ^ 1 && (n - 1) >> i & 1) {
  //     f = false;
  //     break;
  //   }
  // }
  // std::cerr << f << ' ' << n - 1 << '\n';
  if (check(n - 1) && ((n - 1) & ans) == ans) {
    std::cout << n - 1 << '\n';
    return;
  }
  std::cout << ans << '\n';
  return;

//   if (x % 2 == 0) {
//     for (int i = 1; i <= n - 1; i++) {
//       std::cout << 0 << ' ';
//     }
//     std::cout << x << '\n';
//     return;
//   }
//   if (n == 1) {
//     std::cout << x << '\n';
//     return;
//   }
//   int i = 0;
//   while (x >> i & 1) i++;
//   std::cout << (x >> i << i) << ' ';
// 
//   n--;
// 
//   int cur = 0, lst = 0;
//   // if (x >> i << i == 0) n--;
//   for (int j = ((x >> i << i) == 0 ? 1 : 0); n-- > 1; j++) {
//     if (j >= (1ll << i)) {
//       break;
//     }
//     std::cout << j << ' ';
//     lst = j;
//     cur |= j;
//   }
//   int ans = 0;
//   for (int j = i - 1; j >= 0; j--) {
//     if (cur >> j & 1 ^ 1) {
//       ans |= 1 << j;
//     }
//   }
//   // std::cerr << lst << '\n';
//   std::cout << (ans == 0 && lst + 1 < (1ll << i) ? lst + 1 : ans) << ' ';
//   while (n-->0) std::cout << 0 << ' ';
//   std::cout << '\n';
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