#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<std::pair<int, int>>> ask(n + 1);
  for (int i = 1; i <= q; i++) {
    int l, r, x;
    std::cin >> l >> r >> x;
    ask[r].push_back({l, x});
  }

  std::vector<std::pair<int, int>> d(63, {0, 0});

  auto add = [&](int x, int idx) {
    for (int i = 62; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i].first) {
          x ^= d[i].first;
        } else {
          d[i] = {x, idx};
          return;
        }
      }
    }
  };

  auto query = [&](int l, int x) {
    for (int i = 62; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i].first && d[i].second >= l) {
          x ^= d[i].first;
        } else {
          return false;
        }
      }
    }
    return true;
  };

  for (int i = n; i >= 1; i--) {
    add(a[i], i);
    for (auto [l, x] : ask[i]) {
      std::cout << (query(l, x) ? "Yes" : "No") << '\n';
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}