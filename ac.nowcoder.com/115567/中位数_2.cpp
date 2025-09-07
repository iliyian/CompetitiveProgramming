#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), vec;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  // for (int i = 1; i < (1 << n); i++) {
  //   int x = 0;
  //   for (int j = 0; j < n; j++) {
  //     if (i >> j & 1) {
  //       x ^= a[j];
  //     }
  //   }
  //   vec.push_back(x);
  // }
  // std::ranges::sort(vec);
  // for (int i : vec) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  std::vector<int> d(63);
  for (int i = 0; i < n; i++) {
    int x = a[i];
    for (int j = 62; j >= 0; j--) {
      if (x >> j & 1) {
        if (!d[j]) {
          d[j] = x;
          break;
        } else {
          x ^= d[j];
        }
      }
    }
  }
  std::vector<int> v;
  for (int i = 0; i <= 62; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (d[i] >> j & 1) {
        d[i] ^= d[j];
      }
    }
    if (d[i]) {
      v.push_back(d[i]);
    }
  }
  // for (auto i : v) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  std::cout << v.back() << '\n';
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