#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> op(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> op[i].first >> op[i].second;
  }
  std::sort(op.begin() + 1, op.end());
  int px = 0, py = 0;
  for (int i = 1; i <= m; i++) {
    auto [x, y] = op[i];
    if (x == px && y != py) {
      std::cout << "No\n";
      return;
    }
    if (y >= x - px && y != py + x - px) {
      std::cout << "No\n";
      return;
    }
    px = x, py = y;
  }
  std::cout << "Yes\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}