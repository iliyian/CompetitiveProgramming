#include <bits/stdc++.h>
#define int long long

void solve() {
  int sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;
  std::cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;
  int mxd = std::abs((sx1 + sx2) - (tx1 + tx2));
  int myd = std::abs((sy1 + sy2) - (ty1 + ty2));
  std::cout << std::max(mxd, myd) << '\n';
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