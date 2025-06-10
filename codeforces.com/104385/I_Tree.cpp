#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> f(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    f[x] ^= w;
    f[y] ^= w;
  }
  while (q--) {
    int op, x, y, z;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x >> y >> z;
      f[x] ^= z;
      f[y] ^= z;
    } else {
      std::cin >> x;
      std::cout << f[x] << '\n';
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