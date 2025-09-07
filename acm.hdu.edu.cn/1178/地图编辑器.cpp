#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  auto in = [&](int x, int y) -> bool {
    return x >= 1 && x <= n && y >= 1 && y <= m;
  };
  auto p = [&](int x, int y, int v) {
    if (in(x, y)) {
      a[x][y] = std::max(a[x][y], v);
    }
  };
  auto paint = [&](int x, int y) -> void {
    for (int i = 0; i < 5; i++) {
      p(x - i, y, x);
    }
    p(x - 2, y - 1, x);
    p(x - 2, y - 2, x);
    p(x - 2, y + 1, x);
    p(x - 2, y + 2, x);
    p(x - 3, y - 1, x);
    p(x - 3, y + 1, x);
  };
  std::vector<int> rx(n + 1);
  for (int i = 1; i <= k; i++) {
    int x, y;
    std::cin >> x >> y;
    paint(x, y);
    rx[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) {
        std::cout << '.';
      } else {
        std::cout << rx[a[i][j]];
      }
    }
    std::cout << '\n';
  }
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