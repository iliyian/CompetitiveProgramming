#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  int a[2][2] = {
    {1, 4},
    {3, 2},
  };
  auto query = [&](auto self, int x, int y, int n) -> int {
    if (n == 1) {
      return a[x - 1][y - 1];
    }
    int one = 1ll << (2 * n - 2);
    if (x > (1ll << (n - 1))) {
      if (y > (1ll << (n - 1))) {
        return one + self(self, x - (1ll << (n - 1)), y - (1ll << (n - 1)), n - 1);
      } else {
        return one * 2 + self(self, x - (1ll << (n - 1)), y, n - 1);
      }
    }
    if (x <= (1ll << (n - 1))) {
      if (y > (1ll << (n - 1))) {
        return one * 3 + self(self, x, y - (1ll << (n - 1)), n - 1);
      } else {
        return self(self, x, y, n - 1);
      }
    }
    assert(false);
  };
  auto queryxy = [&](auto self, int v, int n) -> std::pair<int, int> {
    if (n == 1) {
      if (v == 1) return {1, 1};
      if (v == 2) return {2, 2};
      if (v == 3) return {2, 1};
      if (v == 4) return {1, 2};
    }
    int one = 1ll << (2 * n - 2), w = 1ll << (n - 1);
    if (v > one * 3) {
      auto [x, y] = self(self, v - one * 3, n - 1);
      return {x, y + w};
    }
    if (v > one * 2) {
      auto [x, y] = self(self, v - one * 2, n - 1);
      return {x + w, y};
    }
    if (v > one * 1) {
      auto [x, y] = self(self, v - one * 1, n - 1);
      return {x + w, y + w};
    }
    return self(self, v, n - 1);
  };
  while (q--) {
    std::string op;
    int x, y;
    std::cin >> op;
    if (op == "<-") {
      std::cin >> x;
      auto [_x, _y] = queryxy(queryxy, x, n);
      std::cout << _x << ' ' << _y << '\n';
    } else {
      std::cin >> x >> y;
      std::cout << query(query, x, y, n) << '\n';
    }
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