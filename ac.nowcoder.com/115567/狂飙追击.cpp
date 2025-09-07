#include <bits/stdc++.h>
#define int long long

void solve() {
  int sx, sy, tx, ty;
  std::cin >> sx >> sy >> tx >> ty;
  std::queue<std::array<int, 3>> q;
  q.push({sx, sy, 0});
  while (!q.empty()) {
    auto [x, y, d] = q.front(); q.pop();
    if (x == tx && y == ty) {
      std::cout << d << '\n';
      return;
    }
    int mx = std::max(x, y);
    if (x + mx <= tx)
      q.push({x + mx, y, d + 1});
    if (y + mx <= ty)
      q.push({x, y + mx, d + 1});
  }
  std::cout << -1 << '\n';
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