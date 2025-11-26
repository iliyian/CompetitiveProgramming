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
 * @File    : C_1_Interactive_RBS_Easy_Version.cpp
 * @Time    : 2025-11-24 17:16:58
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    std::cout << "? "  << n - mid + 1 << ' ';
    for (int i = mid; i <= n; i++) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
    int x;
    std::cin >> x;
    if (x > 0) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  if (ans == -1) {
    ans = n;
  }
  std::string s;
  for (int i = 1; i + 1 <= n; i += 2) {
    std::cout << "? " << 6 << ' ';
    std::cout << ans << ' ' << ans << ' ' << i << ' ' << i << ' ' << ans << ' ' << i + 1 << std::endl;
    int res;
    std::cin >> res;
    if (res == 0) {
      s.push_back('(');
      s.push_back('(');
    }
    if (res == 1) {
      s.push_back('(');
      s.push_back(')');
    }
    if (res == 2) {
      s.push_back(')');
      s.push_back('(');
    }
    if (res == 4) {
      s.push_back(')');
      s.push_back(')');
    }
  }
  if (n % 2 == 1) {
    if (ans == n) {
      s.push_back('(');
    } else {
      std::cout << "? " << 2 << ' ';
      std::cout << ans << ' ' << n << std::endl;
      int x;
      std::cin >> x;
      s.push_back(x == 1 ? ')' : '(');
    }
  }
  std::cout << "! " << s << std::endl;
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
