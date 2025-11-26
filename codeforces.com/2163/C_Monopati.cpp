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
 * @File    : C_Monopati.cpp
 * @Time    : 2025-11-10 23:28:21
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(2, std::vector<int>(n));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j];
    }
  }
  std::vector<int> prel(n + 1), prer(n + 1), sufl(n + 1), sufr(n + 1);
  prel[0] = n * 2;
  prer[0] = 1;
  sufl[n] = n * 2;
  sufr[n] = 1;
  std::vector<int> mxl(n * 2 + 1);
  for (int i = 0; i < n; i++) {
    prel[i + 1] = std::min(a[0][i], prel[i]);
    prer[i + 1] = std::max(a[0][i], prer[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    sufl[i] = std::min(a[1][i], sufl[i + 1]);
    sufr[i] = std::max(a[1][i], sufr[i + 1]);
  }
  for (int i = 1; i <= n; i++) {
    int l = std::min(prel[i], sufl[i - 1]), r = std::max(prer[i], sufr[i - 1]);
    mxl[r] = std::max(mxl[r], l);
  }
  int ans = 0;
  for (int i = 1; i <= n * 2; i++) {
    mxl[i] = std::max(mxl[i], mxl[i - 1]);
    // std::cerr << i << ' ' << mxl[i] << '\n';
    ans += mxl[i];
  }
  std::cout << ans << '\n';
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
