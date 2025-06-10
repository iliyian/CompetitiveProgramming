#include <bits/stdc++.h>
#define int long long

std::map<std::array<int, 3>, int> sg;

int get(int n, int m, int k) {
  if (!n && !m) return 0;
  if (sg.count({n, m, k})) return sg[{n, m, k}];
  std::set<int> s;
  for (int i = 1; i <= std::min(n, k); i++) {
    s.insert(get(n - i, m, k));
  }
  for (int i = 1; i <= std::min(m, k); i++) {
    s.insert(get(n, m - i, k));
  }
  for (int i = 0;; i++) {
    if (!s.count(i)) {
      return sg[{n, m, k}] = i;
    }
  }
}

std::map<std::array<int, 2>, int> sgg;

int get(int n, int k) {
  if (!n) return 0;
  if (sgg.count({n, k})) return sgg[{n, k}];
  std::set<int> s;
  for (int i = 1; i <= std::min(n, k); i++) {
    s.insert(get(n - i, k));
  }
  for (int i = 0;; i++) {
    if (!s.count(i)) {
      return sgg[{n, k}] = i;
    }
  }
}

void solve() {
  int n, m, k, c;
  std::cin >> n >> m >> k >> c;
  int minx = n + 1, miny = m + 1;
  for (int i = 1; i <= c; i++) {
    int x, y;
    std::cin >> x >> y;
    x++, y++;
    minx = std::min(x, minx);
    miny = std::min(y, miny);
  }

  // int lim = 20;
  // for (int i = 0; i <= lim; i++) {
  //   for (int k = 1; k <= i; k++) {
  //     int x = get(i, k);
  //     if (i > k * 2 && i % 2 == 0 && k != 1) {
  //       if (get(i, k) != get(i / 2, k) * 2) {
  //         std::cout << -1 << ' ' << i << ' ' << k << '\n';
  //       }
  //     }
  //     std::cout << i << ' ' << k << ' ' << get(i, k) << '\n';
  //   }
  // }
  int x = get(minx - 1, miny - 1, k);
  // for (int i = 0; i <= lim; i++) {
  //   for (int j = 0; j <= i; j++) {
  //     for (int k = 1; k <= std::max(i, j); k++) {
  //       int x = get(i, j, k);
  //       if (x == 0) {
  //         std::cout << i << ' ' << j << ' ' << k << ' ' << (i ^ j) << '\n';
  //         std::cout << get(i, j, k) << '\n';
  //       }
  //     }
  //   }
  // }
  std::cout << (x == 0 ? "别急" : "开吃") << '\n';
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