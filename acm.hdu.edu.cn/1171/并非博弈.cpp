// date: 2025-03-01 07:57:59
// tag: 很合理的要开long double的情况，哎这种博弈题但凡先随便打个表，类似威佐夫博弈？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

//   std::map<std::pair<int, int>, bool> mp;
//   auto dfs = [&](auto self, int a, int b) -> bool {
//     if (a < b) std::swap(a, b);
//     // std::cerr << a << ' ' << b << '\n';
//     if (!a || !b) return false;
//     if (mp.count({a, b})) return mp[{a, b}];
//     for (int k = 1; k * b <= a; k++) {
//       if (!self(self, a - k * b, b)) {
//         return mp[{a, b}] = true;
//       }
//     }
//     return mp[{a, b}] = false;
//   };
// 
  long double sqrtl5 = sqrtl(5);
// 
//   int n = 50;
//   for (int a = 1; a <= n; a++) {
//     int cnt = 0;
//     for (int b = 1; b <= a; b++) {
//       if (dfs(dfs, a, b)) {
//         // std::cout << b << ' ';
//         cnt++;
//       }
//     }
//     std::cout << a << ' ' << cnt << ' ' << 1.0 * cnt / a << ' ' << a * (sqrt5 - 1) / 2.0 << '\n';
//     // std::cout << '\n';
//   }
//   return 0;

  int t = 1;
  std::cin >> t;
  int ans = 0;
  while (t--) {
    int x;
    std::cin >> x;
    ans ^= (int)std::ceil(x * (sqrtl5 - 1) / 2.0);
  }
  std::cout << ans << '\n';
  return 0;
}