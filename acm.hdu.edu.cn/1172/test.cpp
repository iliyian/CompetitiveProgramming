// 树状数组常数约在0.5左右

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n = 1000000, real = 0, up = 0;
  for (int i = 1; i <= n; i++) {
    real += __builtin_popcountll(i);
    up += std::__lg(i);
    if (i % (int)1e4 == 0) {
      std::cout << i << ": ";
      std::cout << real << ' ' << up << ' ' << 1.0 * real / up << '\n';
    }
  }
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