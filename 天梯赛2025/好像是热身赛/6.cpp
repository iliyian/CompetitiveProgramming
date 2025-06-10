#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  // int N = 1e6;
  // std::vector<int> a(N + 1);
  // for (int i = 1; i <= N; i++) {
  //   a[i] = i * i + a[i - 1];
  // }
  int l = 3, d = 7;
  for (int i = 2; i <= n; i++) {
    l += d;
    d += 4;
  }
  int i = l + n * 2;
  // for (int i = n * 2 + 1; i <= N; i++) {
  //   int r = a[i] - a[i - n];
  //   int l = a[i - n] - a[i - n * 2 - 1];
  //   if (l == r) {
      for (int j = i - n * 2; j <= i - n; j++) {
        std::cout << j << "^" << 2;
        if (j == i - n) {
          std::cout << " =";
        } else {
          std::cout << " + ";
        }
      }
      std::cout << '\n';
      for (int j = i - n + 1; j <= i; j++) {
        std::cout << j << "^" << 2;
        if (j == i) {
          std::cout << '\n';
        } else {
          std::cout << " + ";
        }
      }
      // return;
  //   }
  // }
}

// 1 2 3 4
// 3 10 21 36 55 78
// 7 11 15 19 23
// 
int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}