// date: 2025-01-29 14:35:24
// tag: 仍然是压缩已经选择的物品的状压dp，不过需要一定的剪枝，然后枚举当前选择的物品，把状态或上去就可以的很套路的做法
// 本题大概就是状态的压缩比较不敢想，毕竟n=24了，剪枝还是很必要的

#include <bits/stdc++.h>
// #define int long long

constexpr int N = 12;
int a[N][N][N], f[N][1 << N][1 << N];

void solve() {
  int n;
  std::cin >> n;
  // std::vector a(n, std::vector<std::vector<int>>(n, std::vector<int>(n)));
  // std::vector f(n, std::vector<std::vector<int>>(
  //                      1 << n, std::vector<int>(1 << n, INT_MAX)));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        std::cin >> a[i][j][k];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      for (int k = 0; k < (1 << n); k++) {
        f[i][j][k] = INT_MAX;
      }
    }
  }
  for (int y = 0; y < n; y++) {
    for (int z = 0; z < n; z++) {
      f[0][1 << y][1 << z] = a[0][y][z];
    }
  }
  for (int x = 1; x < n; x++) {
    for (int sy = 0; sy < (1 << n); sy++) {
      if (__builtin_popcountll(sy) != x) continue;
      for (int y = 0; y < n; y++) {
        if (sy >> y & 1) continue;
        for (int sz = 0; sz < (1 << n); sz++) {
          if (__builtin_popcountll(sz) != x) continue;
          for (int z = 0; z < n; z++) {
            if (sz >> z & 1) continue;
            f[x][sy ^ (1 << y)][sz ^ (1 << z)] = std::min(f[x][sy ^ (1 << y)][sz ^ (1 << z)], f[x - 1][sy][sz] + a[x][y][z]);
          }
        }
      }
    }
  }
  std::cout << f[n - 1][(1 << n) - 1][(1 << n) - 1] << '\n';
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