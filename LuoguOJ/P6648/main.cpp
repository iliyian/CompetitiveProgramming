// date: 2024-07-15 14:00:32
// tag: 二维st

#include <bits/stdc++.h>

void solve() {
  int n, K;
  std::cin >> n >> K;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  std::vector<std::vector<std::array<int, 2>>> mx(n + 1, std::vector<std::array<int, 2>>(n + 1, std::array<int, 2>()));
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      std::cin >> a[i][j];
      mx[i][j][cur] = a[i][j];
    }
  }

  cur ^= 1;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= n - 1; j++) {
      mx[i][j][cur] = std::max({
        mx[i][j][cur ^ 1],
        mx[i + 1][j][cur ^ 1],
        mx[i + 1][j + 1][cur ^ 1]
      });
    }
  }

  int len = std::__lg(K);
  for (int k = 2; k <= len; k++) {
    cur ^= 1;
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      for (int j = 1; j + (1 << k) - 1 <= n; j++) {
        mx[i][j][cur] = std::max({
          mx[i][j][cur ^ 1],
          mx[i + (1 << (k - 2))][j][cur ^ 1],
          mx[i + (1 << (k - 1))][j][cur ^ 1],
          mx[i + (1 << (k - 2))][j + (1 << (k - 2))][cur ^ 1],
          mx[i + (1 << (k - 1))][j + (1 << (k - 2))][cur ^ 1],
          mx[i + (1 << (k - 1))][j + (1 << (k - 1))][cur ^ 1],
        });
     
        // int Mx = 0;
        // for (int dx = 0; dx < (1 << k); dx++) {
        //   for (int dy = 0; dy <= dx; dy++) {
        //     Mx = std::max(Mx, a[i + dx][j + dy]);
        //   }
        // }

        // assert(mx[i][j][cur] == Mx);
      }
    }
  }

  long long ans = 0, real = 0;
  for (int i = 1; i + K - 1 <= n; i++) {
    for (int j = 1; j + K - 1 <= n && j <= i; j++) {
      int I = i + K - 1, J = j + K - 1, My = 0;
      int l = (I - (1 << len) + 1), r = J - (1 << len) + 1;
      My = std::max({
        mx[i][j][cur],
        mx[I - (1 << len) + 1][j][cur],
        mx[I - (1 << len) + 1][J - (1 << len) + 1][cur],

        mx[(i + l) >> 1][j][cur],
        mx[(i + l) >> 1][(j + r) >> 1][cur],
        mx[l][(j + r) >> 1][cur],
      });

      ans += My;
      
      // int Mx = 0;
      // for (int dx = 0; dx < K; dx++) {
      //   for (int dy = 0; dy <= dx; dy++) {
      //     Mx = std::max(Mx, a[i + dx][j + dy]);
      //   }
      // }
      // real += Mx;
    }
  }

  std::cout << ans << '\n';
  // std::cout << real << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  
  solve();
}