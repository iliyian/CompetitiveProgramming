#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  int l = (n + 1) / 2, r = (n + 1) / 2;
  int tot = 1;
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      for (int j = l; j <= r; j++) {
        for (int k = l; k <= r; k++) {
          if (!a[j][k]) {
            a[j][k] = tot++;
          }
        }
      }
      l--;
    } else {
      for (int j = r; j >= l; j--) {
        for (int k = r; k >= l; k--) {
          if (!a[j][k]) {
            a[j][k] = tot++;
          }
        }
      }
      r++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cout << a[i][j] - 1 << " \n"[j == n];
    }
  }
  // int ans = 0;
  // for (int lx = 1; lx <= n; lx++) {
  //   for (int ly = 1; ly <= n; ly++) {
  //     for (int rx = lx; rx <= n; rx++) {
  //       for (int ry = ly; ry <= n; ry++) {
  //         int mex = 0;
  //         for (int x = lx; x <= rx; x++) {
  //           for (int y = ly; y <= ry; y++) {
  //             if (a[x][y] - 1 == mex) {
  //               mex++;
  //             }
  //           }
  //         }
  //         ans += mex;
  //         // std::cout << mex << '\n';
  //       }
  //     }
  //   }
  // }
  // std::cout << ans << '\n';
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