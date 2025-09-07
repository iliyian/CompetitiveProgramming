#include <bits/stdc++.h>
#define int long long

int qpow(int a, int b, int p) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int a, c, p;
  std::cin >> a >> c >> p;
  std::cout << (p - 1) * (p - 1) << '\n';
  // std::cout << qpow(a, c, p) << '\n';
  // for (int i = 1; i <= 100000; i++) {
  //   int b = i;
  //   if (qpow(a, b, p) == qpow(b, c, p)) {
  //     std::cout << qpow(a, b, p) << ' ' << qpow(b, c, p) << ' ' << b << '\n';
  //   }
  // }
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