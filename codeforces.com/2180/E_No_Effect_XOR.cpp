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
 * @File    : E_No_Effect_XOR.cpp
 * @Time    : 2025-12-20 00:15:45
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int get(int r, int k) {
  if (r < (1ll << k)) return 0;
  int ans = (r >> (k + 1)) << k;
  if (r >> k & 1) ans += (r & ((1ll << k) - 1)) + 1;

  // int good = 0;
  // for (int i = 1; i <= r; i++) {
  //   good += i >> k & 1;
  // }
  // assert(ans == good);

  return ans;
}

void solve(int l, int r) {
  int tot = 0;
  for (int i = 1; i <= 1000; i++) {
    int cnt = 0;
    for (int j = l; j <= r; j++) {
      if ((j ^ i) >= l && (j ^ i) <= r) {
        cnt++;
      }
    }
    if (cnt == r - l + 1) {
      std::cerr << i << ' ';
      tot++;
    }
  }
  std::cerr << '\n';
  if (tot == 7) {
    // std::cout << l << ' ' << r << ' ' << tot << ' ' << r - l + 1 << '\n';
  }
}

void solve() {
  int l, r;
  std::cin >> l >> r;
  int lcnt = 0, rcnt = 0;
  while ((r ^ ((1 << (lcnt + 1)) - 1)) <= r) lcnt++;
  
  std::cout << (1ll << (lcnt + rcnt)) - 1 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int r = 1; r <= 5000; r++) {
  //   for (int k = 0; k <= 30; k++) {
  //     get(r, k);
  //   }
  // }

  solve(4, 11);
  return 0;

  for (int l = 1; l <= 500; l++) {
    for (int r = l; r <= 500; r++) {
      solve(l, r);
    }
  }

  return 0;

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
