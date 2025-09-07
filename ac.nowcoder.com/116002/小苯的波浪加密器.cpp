#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, l1, r1, l2, r2;
  std::cin >> n >> l1 >> r1 >> l2 >> r2;
  int x, y;
  std::cin >> x;
  if (n >= 3) {
    std::cin >> y;
  }
  for (int i = 1; i <= n - 4; i++) {
    int x;
    std::cin >> x;
  }
  for (int i = l1; i <= std::min(l1 + 10, r1); i++) {
    for (int j = l2; j <= std::min(l2 + 10, r2); j++) {
      if (i * j % 10 == x && (n == 3 || j * x % 10 == y)) {
        std::cout << i << ' ' << j << '\n';
        return;
      }
    }
  }
  std::cout << -1 << ' ' << -1 << '\n';
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