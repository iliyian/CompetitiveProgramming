/*

LLLLLLLLLLL             IIIIIIIIIIYYYYYYY       YYYYYYYIIIIIIIIII               AAA               NNNNNNNN        NNNNNNNN
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I              A:::A              N:::::::N       N::::::N
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I             A:::::A             N::::::::N      N::::::N
LL:::::::LL             II::::::IIY::::::Y     Y::::::YII::::::II            A:::::::A            N:::::::::N     N::::::N
  L:::::L                 I::::I  YYY:::::Y   Y:::::YYY  I::::I             A:::::::::A           N::::::::::N    N::::::N
  L:::::L                 I::::I     Y:::::Y Y:::::Y     I::::I            A:::::A:::::A          N:::::::::::N   N::::::N
  L:::::L                 I::::I      Y:::::Y:::::Y      I::::I           A:::::A A:::::A         N:::::::N::::N  N::::::N
  L:::::L                 I::::I       Y:::::::::Y       I::::I          A:::::A   A:::::A        N::::::N N::::N N::::::N
  L:::::L                 I::::I        Y:::::::Y        I::::I         A:::::A     A:::::A       N::::::N  N::::N:::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I        A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I       A:::::::::::::::::::::A     N::::::N    N::::::::::N
  L:::::L         LLLLLL  I::::I         Y:::::Y         I::::I      A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N
LL:::::::LLLLLLLLL:::::LII::::::II       Y:::::Y       II::::::II   A:::::A             A:::::A   N::::::N      N::::::::N
L::::::::::::::::::::::LI::::::::I    YYYY:::::YYYY    I::::::::I  A:::::A               A:::::A  N::::::N       N:::::::N
L::::::::::::::::::::::LI::::::::I    Y:::::::::::Y    I::::::::I A:::::A                 A:::::A N::::::N        N::::::N
LLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII    YYYYYYYYYYYYY    IIIIIIIIIIAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNN

 * 
 * ==============================================================================
 * @Author  : iliyian
 * @File    : T_708535_成都之泪.cpp
 * @Time    : 2025-12-14 15:15:11
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>

void solve() {
  int n, k;
  std::cin >> n >> k;
  int len = 400;
  int cnt = (n + len - 1) / len;
  std::vector<int> l(cnt + 1), r(cnt + 1);
  for (int i = 1; i <= cnt; i++) {
    l[i] = std::min(n, r[i - 1] + 1);
    r[i] = std::min(n, l[i] + len - 1);
  }
  auto id = [&](int x) {
    return (x - 1) / len + 1;
  };
  std::vector<int> a(n + 1), offset(n + 1);
  std::vector<std::vector<int>> bucket(cnt + 1, std::vector<int>(n + 1));
  auto update = [&](int L, int R, int val) {
    int lid = id(L), rid = id(R);
    if (lid == rid) {
      for (int i = L; i <= R; i++) {
        bucket[lid][a[i] + offset[lid]]--;
        a[i] += val;
        bucket[lid][a[i] + offset[lid]]++;
      }
    } else {
      for (int i = L; i <= r[lid]; i++) {
        bucket[lid][a[i] + offset[lid]]--;
        a[i] += val;
        bucket[lid][a[i] + offset[lid]]++;
      }
      for (int i = l[rid]; i <= R; i++) {
        bucket[lid][a[i] + offset[lid]]--;
        a[i] += val;
        bucket[lid][a[i] + offset[lid]]++;
      }
      for (int i = lid + 1; i <= rid - 1; i++) {
        offset[i] += val;
        if (val == 1) {
          for (int j = n - 1; j >= 0; j--) {
            bucket[i][j + 1] = bucket[i][j];
          }
        } else {
          for (int j = 0; j < n; j++) {
            bucket[i][j] = bucket[j][j + 1];
          }
        }
      }
    }
  };
  std::vector<std::pair<int, int>> line(n);
  for (auto &[l, r] : line) {
    std::cin >> l >> r;
    l--, r--;
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
