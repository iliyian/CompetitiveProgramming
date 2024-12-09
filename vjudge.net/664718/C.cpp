// 疑似状压dp远不如状压搜索好写

// date: 2024-12-08 22:00:43
// tag: 模拟，状压搜索

#include <bits/stdc++.h>
#define int long long

int d[19][19], a[19], f[1 << 19];

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 0; i < 19; i++) {
    std::fill(d[i], d[i] + 19, -1);
  }
  std::fill(f, f + (1 << 19), -1);

  d[0][1] = 2, d[0][4] = 9, d[0][3] = 7;
  d[1][4] = 8, d[1][5] = 10;
  d[2][1] = 0, d[2][5] = 9, d[2][6] = 11;
  d[3][4] = 5, d[3][8] = 13;
  d[4][8] = 12, d[4][9] = 14, d[4][5] = 6;
  d[5][4] = 3, d[5][9] = 13, d[5][10] = 15;
  d[6][5] = 4, d[6][10] = 14;
  d[7][3] = 0, d[7][8] = 9, d[7][12] = 16;
  d[8][4] = 1, d[8][9] = 10, d[8][13] = 17;
  d[9][4] = 0, d[9][5] = 2, d[9][8] = 7, d[9][10] = 11, d[9][13] = 16, d[9][14] = 18;
  d[10][5] = 1, d[10][9] = 8, d[10][14] = 17;
  d[11][10] = 9, d[11][6] = 2, d[11][15] = 18;
  d[12][8] = 4, d[12][13] = 14;
  d[13][8] = 3, d[13][9] = 5, d[13][14] = 15;
  d[14][9] = 4, d[14][10] = 6, d[14][13] = 12;
  d[15][14] = 13, d[15][10] = 5;
  d[16][12] = 7, d[16][17] = 18, d[16][13] = 9;
  d[17][13] = 8, d[17][14] = 10;
  d[18][17] = 16, d[18][14] = 9, d[18][15] = 11;

  for (int i = 0; i < 19; i++) {
    std::cin >> a[i];
  }

  auto dfs = [&](auto self, int S) -> int {
    if (!S) return 0;
    if (f[S] != -1) return f[S];
    for (int i = 0; i < 19; i++) {
      if (S >> i & 1) {
        f[S] = std::max(f[S], self(self, S ^ (1 << i)));
        for (int j = 0; j < 19; j++) {
          int k = d[i][j];
          if (k == -1) continue;
          if ((S >> i & 1) && (S >> j & 1) && !(S >> k & 1)) {
            int ns = S ^ (1 << i) ^ (1 << j) ^ (1 << k);
            f[S] = std::max(f[S], self(self, ns) + a[j]);
          }
        }
      }
    }
    return f[S];
  };

  int q;
  std::cin >> q;
  while (q--) {
    int cur = 0;
    for (int i = 0; i < 19; i++) {
      char ch;
      std::cin >> ch;
      cur ^= (ch == '#') << i;
    }
    std::cout << dfs(dfs, cur) << '\n';
  }

  return 0;
}