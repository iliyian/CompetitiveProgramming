#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  int t = 1;
  for (int i = 0; i < k; i++) {
    t = t * 10;
  }
  int c = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    __int128 tmp = __int128(c) * x;
    if (tmp >= t) {
      c = 1;
    } else {
      c = tmp;
    }
  }
  std::cout << c << '\n';
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