#include <bits/stdc++.h>
#define int long long

int a[12][12] {};

void solve() {
  int mp[] = {0, 3, 2, 1, 4, 0, 6, 5, 8, 7, 0, 9, 12, 11, 10, 0};
  int cur[12] {};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int x;
      std::cin >> x;
      int id = mp[i * 4 + j];
      if (id != 0) {
        cur[id - 1] = x;
      }
    }
  }
  int res = 0;
  while (1) {
    bool f = false;
    for (int i = 0; i < 12; i++) {
      if (cur[i]) {
        f = true;
        break;
      }
    }
    if (!f) break;
    res++;

    int mxcnt = 0, mxS = 0, mxsum = 0;
    // for (int S = (1ll << 12) - 1; S >= 0; S--) {
    for (int S = 0; S < (1 << 12); S++) {
      bool f = true;
      for (int i = 0; i < 12; i++) {
        if (S >> i & 1) {
          if (!cur[i]) {
            f = false;
            goto end;
          }
          for (int j = i + 1; j < 12; j++) {
            if (S >> j & 1) {
              if (!cur[j]) {
                f = false;
                goto end;
              }
              if (a[i][j]) {
                f = false;
                goto end;
              }
            }
          }
        }
      }
      end:;
      if (f) {
        int _mxsum = 0;
        int cnt = __builtin_popcountll(S);
        for (int i = 0; i < 12; i++) {
          if (mxS >> i & 1) {
            _mxsum += cur[i];
          }
        }
        if (cnt > mxcnt || cnt == mxcnt && _mxsum > mxsum) {
          mxcnt = cnt, mxS = S, mxsum = _mxsum;
        }
      }
    }
    // std::cerr << mxcnt << '\n';
    for (int i = 0; i < 12; i++) {
      if (mxS >> i & 1) {
        cur[i]--;
        // if (i != 0 && i != 3 && i != 6 && i != 9) {
        //   std::cerr << i << ' '; 
        // }
      }
      // std::cerr << cur[i] << ' ';
    }
    // std::cerr << '\n';
  }
  std::cout << res << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  a[1][4] = a[1][8] = a[1][10] = a[1][11] = 1;
// 2:5 9 11 12
  a[2][4] = a[2][5] = a[2][7] = a[2][11] = 1;
// 3:5 6 8 12
  a[4][1] = a[4][2] = a[4][7] = a[4][11] = 1;
// 5:2 3 8 12
  a[5][2] = a[5][7] = a[5][8] = a[5][10] = 1;
// 6:3 8 9 11
  a[7][2] = a[7][4] = a[7][5] = a[7][10] = 1;
// 8:3 5 6 11
  a[8][1] = a[8][5] = a[8][10] = a[8][11] = 1;
// 9:2 6 11 12
  a[10][1] = a[10][5] = a[10][7] = a[10][8] = 1;
// 11:2 6 8 9
  a[11][1] = a[11][2] = a[11][4] = a[11][8] = 1;
// 12:2 3 5 9

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}