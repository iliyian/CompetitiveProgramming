#include <bits/stdc++.h>
#define int long long

/*
#################
#################
#################
####..#####..####
###....###....###
###....###....###
####..#####..####
#################
#################
#################
*/

std::string em[] = {
  "#..#",
  "....",
  "....",
  "#..#",
};

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '.' + a[i];
  }
  auto check = [&](int x, int y) {
    if (x <= 3 || x > n || y <= 3 || y > m) return false;
    for (int i = x - 3; i <= x; i++) {
      for (int j = y - 3; j <= y; j++) {
        if (em[i - (x - 3)][j - (y - 3)] != a[i][j]) {
          return false;
        }
      }
    }
    return true;
  };
  auto clear = [&](int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
      for (int j = y1; j <= y2; j++) {
        a[i][j] = '.';
      }
    }
  };
  int ans1 = 0, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (check(i, j)) {
        if (check(i, j + 7)) {
          ans1++;
          clear(i - 6, j - 6, i + 3, j + 10);
        }
        if (check(i + 7, j)) {
          ans1++;
          clear(i - 6, j - 6, i + 10, j + 3);
        }
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     std::cerr << a[i][j];
  //   }
  //   std::cerr << '\n';
  // }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (check(i, j)) {
        ans2++;
      }
    }
  }
  std::cout << ans1 << ' ' << ans2 << '\n';
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