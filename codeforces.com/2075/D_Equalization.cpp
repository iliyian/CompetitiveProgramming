#include <bits/stdc++.h>
#define int long long

int f[63][63];

std::map<std::array<int, 2>, int> mp;
int solve(int x, int y, int prv) {
  if (x == 0 && y == 0) return prv;
  if (mp.count({x, y}) && mp[{x, y}] < prv) return mp[{x, y}];
  int mn = LLONG_MAX / 3;
  for (int i = 1; i <= x; i++) {
    if (prv >> i & 1) continue;
    mn = std::min(mn, solve(x - i, y, prv + (1ll << i)));
  }
  for (int i = 1; i <= y; i++) {
    if (prv >> i & 1) continue;
    mn = std::min(mn, solve(x, y - i, prv + (1ll << i)));
  }
  return mp[{x, y}] = mn;
  // return mn;
}

void solve() {
  int x, y;
  std::cin >> x >> y;
  if (x == y) {
    std::cout << 0 << '\n';
    return;
  }
  // std::cerr << x << ' ' << y << '\n';
  int ans = LLONG_MAX;
  for (int i = 0; i < 63; i++) {
    for (int j = 0; j < 63; j++) {
      // if (i == j) continue;
      if ((x >> i) == (y >> j)) {
        // std::cerr << (x >> i) << ' ' << (y >> j) << ' ' << i << ' ' << j << ' ' << f[i][j] << '\n';
        ans = std::min(ans, f[i][j]);
        // ans = std::min(ans, solve(i, j, 0));
      }
    }
  }
  std::cout << ans << '\n';
}
int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 0; i < 63; i++) {
    for (int j = 0; j < 63; j++) {
      if (i == j) {
        f[i][j] = LLONG_MAX;
        continue;
      }
      if (i) f[i][j] += 1ll << i;
      if (j) f[i][j] += 1ll << j;
    }
  }
  // for (int i = 0; i <= 5; i++) {
  //   for (int j = 0; j <= 5; j++) {
  //     std::cerr << f[i][j] << ' ';
  //   }
  //   std::cerr << '\n';
  // }
  for (int i = 0; i < 63; i++) {
    for (int j = 0; j < 63; j++) {
      for (int k = 0; k < i; k++) {
        int w = i - k;
        if ((1ll << w) + f[k][j] < f[i][j] && ((1ll << w) & f[k][j]) == 0) {
          // if (i == 1 && j == 3) {
          //   std::cerr << k << ' ' << j << ' ' << w << ' ' << f[k][j] << '\n';
          // }
          f[i][j] = f[k][j] + (1ll << w);
        }
      }
      for (int k = 0; k < j; k++) {
        int w = j - k;
        if ((1ll << w) + f[i][k] < f[i][j] && ((1ll << w) & f[i][k]) == 0) {
          // if (i == 1 && j == 3) {
          //   std::cerr << i << ' ' << k << ' ' << w << '\n';
          // }
          f[i][j] = f[i][k] + (1ll << w);
        }
      }
    }
  }
  std::cerr << 4 << ' ' << 9 << ' ' << f[4][9] << '\n';
  std::cerr << 5 << ' ' << 5 << ' ' << f[5][5] << '\n';
// 
  // int lim = 60;
  // for (int i = 0; i < lim; i++) {
  //   for (int j = 0; j < lim; j++) {
  //     if (i == j) continue;
  //     // std::cout << f[i][j] << ' ' << solve(i, j, 0) << ' ' << i << ' ' << j << '\n';
  //     if (f[i][j] != solve(i, j, 0)) {
  //       std::cout << i << ' ' << j << ' ' << f[i][j] << ' ' << solve(i, j, 0) << '\n';
  //     }
  //     // assert(f[i][j] == solve(i, j, 0));
  //   }
  // }

  // std::cerr << "\n";
  // for (int i = 0; i <= 5; i++) {
  //   for (int j = 0; j <= 5; j++) {
  //     std::cerr << f[i][j] << ' ';
  //   }
  //   std::cerr << '\n';
  // }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}