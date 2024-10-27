#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  while (n % 2 == 0 && k > 1) {
    k /= 2, n /= 2;
  }
  if (k == 1) {
    std::cout << (n & 1 ? "Alice" : "Bob") << '\n';
  } else {
    std::cout << "Alice" << '\n';
  }
}

// std::map<std::pair<int, int>, int> m;

// int work(int n, int k, int pre) {
//   if (k >= n) return 1;
//   if (n == 0) return -1;
//   if (m[{n, k}]) return m[{n, k}];
//   for (int i = 1; i <= std::min(n, k); i++) {
//     if (pre % i == 0) {
//       int g = work(n - i, k, i);
//       if (g == -1) return m[{n, k}] = 1;
//     }
//   }
//   return m[{n, k}] = -1;
// }

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("11.in", "r", stdin);

  // work(3, 2, 0);
  // for (int n = 1; n <= 100; n++) {
  //   for (int k = 1; k <= 100; k++) {
  //     int f = work(n, k, 0);
  //     if (f == -1) {
  //       std::cout << n << ' ' << k << ' ' << work(n, k, 0) << '\n';
  //     }
  //   }
  // }
  // return 0;

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  };
  return 0;
}