// date: 2024-09-10 11:56:34
// tag: 线性基，子集异或，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  std::vector<int> d(31);
  int xa = 0, xb = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    xa ^= a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    xb ^= b[i];
  }
  auto insert = [&](int x) {
    for (int i = 30; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i]) {
          x ^= d[i];
        } else {
          d[i] = x;
          return;
        }
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    insert(a[i] ^ b[i]);
  }

  for (int i = 30; i >= 0; i--) {
    int mx = std::max(xa, xb);
    if (std::max(xa ^ d[i], xb ^ d[i]) < mx) {
      xa ^= d[i];
      xb ^= d[i];
    }
  }
  std::cout << std::max(xa, xb) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("J.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}