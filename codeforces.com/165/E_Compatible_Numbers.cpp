// date: 2025-07-30 11:29:38
// tag: sosdp最最入门

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), f(1 << 22, -1);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    f[a[i]] = a[i];
  }
  int mxS = 1 << 22;
  for (int i = 0; i < 22; i++) {
    for (int S = 0; S < mxS; S++) {
      if (S >> i & 1) {
        if (f[S ^ (1 << i)] != -1) {
          f[S] = f[S ^ (1 << i)];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << f[a[i] ^ (mxS - 1)] << ' ';
  }
  std::cout << '\n';
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