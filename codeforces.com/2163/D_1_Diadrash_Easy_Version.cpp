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
 * @File    : D_1_Diadrash_Easy_Version.cpp
 * @Time    : 2025-11-11 00:14:42
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int ask(int l, int r) {
  std::cout << "? " << l << ' ' << r << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> mnl(n + 1, n + 1);
  for (int i = 1; i <= q; i++) {
    int l, r;
    std::cin >> l >> r;
    mnl[r] = std::min(mnl[r], l);
  }
  int prv = n + 1;
  for (int i = n; i >= 1; i--) {
    if (mnl[i] < prv) {
      prv = mnl[i];
    } else {
      mnl[i] = n + 1;
    }
  }
  int ans = 0, mid = (n + 1) / 2;
  if (ask(1, mid) > 0) {
    for (int i = 1; i <= n; i++) {
      if (mnl[i] != n + 1 && mnl[i] <= mid) {
        ans = std::max(ans, ask(mnl[i], i));
      }
    }
  } else {
    for (int i = mid + 1; i <= n; i++) {
      if (mnl[i] != n + 1) {
        ans = std::max(ans, ask(mnl[i], i));
      }
    }
  }
  std::cout << "! " << ans << std::endl;
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
