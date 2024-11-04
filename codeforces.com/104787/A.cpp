#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  int x = 1, y = 1;
  std::set<int> vis;
  for (int i = 1; i < n * 2; i++) {
    std::cout << x << ' ' << y << '\n';
    vis.insert((x - 1) * n + y);
    if (i & 1) x++;
    else y++;
  }
  std::cout << 1 << ' ' << n << '\n';
  vis.insert(n);
  x = 1, y = 1;
  for (int i = n * 2 + 1; i <= k; i++) {
    while (vis.count((x - 1) * n + y)) {
      y++;
      if (y == n + 1) {
        y = 1, x++;
      }
    }
    vis.insert((x - 1) * n + y);
    std::cout << x << ' ' << y << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}