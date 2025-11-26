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
 * @File    : B_Locate.cpp
 * @Time    : 2025-11-03 23:03:13
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void first() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int &i : a) std::cin >> i;
  std::cout << (int)(std::ranges::find(a, 1) > std::ranges::find(a, n)) << '\n';
}

void second() {
  int n, x;
  std::cin >> n >> x;
  int l = 2, r = n, ansR = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    std::cout << "? " << 1 << ' ' << mid << std::endl;
    int ans;
    std::cin >> ans;
    if (ans == n - 1) r = mid - 1, ansR = mid;
    else l = mid + 1;
  }
  l = 1, r = ansR - 1;
  int ansL = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    std::cout << "? " << mid << ' ' << ansR << std::endl;
    int ans;
    std::cin >> ans;
    if (ans == n - 1) l = mid + 1, ansL = mid;
    else r = mid - 1;
  }
  std::cout << "! " << (x ? ansL : ansR) << std::endl;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  int t = 1;
  std::cin >> t;

  while (t--) {
    if (s == "first") {
      first();
    } else {
      second();
    }
  }

  return 0;
}
