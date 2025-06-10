// date: 2025-04-16 12:34:10
// tag: 性质推导数学题

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  } 
  return ans;
}

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  int col = 0, cnt = 0, side = 0;
  for (int i = 1; i <= k; i++) {
    int x, y, c;
    std::cin >> x >> y >> c;
    if (x == 1 || x == n) {
      col += c;
    }
    if (y == 1 || y == m) {
      col += c;
    }
    if ((x == 1 || x == n) ^ (y == 1 || y == m)) {
      side++;
    }
  }
  col %= 2;
  if (n * m == k) {
    std::cout << (col ^ 1) << '\n';
    return;
  }
  if (side == (n - 2) * 2 + (m - 2) * 2) {
    if (col == 0) {
      std::cout << qpow(2, n * m - k) << '\n';
    } else {
      std::cout << 0 << '\n';
    }
    return;
  }
  std::cout << qpow(2, n * m - k - 1) << '\n';

  // if (col == 1) {
  //   std::cout << 
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