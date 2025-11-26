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
 * @File    : C_Torn_Lucky_Ticket.cpp
 * @Time    : 2025-11-01 14:20:46
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int calc(int x) {
  int ans = 0;
  while (x) {
    ans += x % 10;
    x /= 10;
  }
  return x;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  std::vector<std::vector<int>> f(6);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    f[a[i].size()].push_back(calc(std::stoll(a[i])));
    // mp[{a[i].size(), calc(std::stoll(a[i]))}]++;
  }
  int ans = 0;
  for (int x = 1; x <= 5; x++) {
    for (int y = 1; y <= 5; y++) {
      if ((x + y) % 2 == 0) {
        int len = (x + y) / 2;
        for (int l = 1; l <= 5; l++) {
          for (int ls : f[l]) {
            
          }
        }
      }
    }
  }
  std::cout << ans << '\n';
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
