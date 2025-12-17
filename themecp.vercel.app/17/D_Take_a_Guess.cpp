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
 * @File    : D_Take_a_Guess.cpp
 * @Time    : 2025-12-10 19:00:43
 * @Comment : 有点adhoc，我想的是(x&y)^(x|y)==(x^y)，真没想到(x&y)+(x|y)==(x+y)
              毕竟x^y,y^z,z^x不能推导出唯一一组x,y,z
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int ask(std::string op, int x, int y) {
  std::cout << op << ' ' << x << ' ' << y << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void solve() {
  int n, k;
  std::cin >> n >> k;
  auto s12 = ask("and", 1, 2) + ask("or", 1, 2);
  auto s13 = ask("and", 1, 3) + ask("or", 1, 3);
  auto s23 = ask("and", 2, 3) + ask("or", 2, 3);
  int a1 = (s12 + s13 + s23) / 2 - s23;
  std::vector<int> v = {a1, s12 - a1, s13 - a1};
  for (int i = 4; i <= n; i++) {
    v.push_back(ask("and", 1, i) + ask("or", 1, i) - a1);
  }
  std::ranges::sort(v);
  std::cout << "finish " << v[k - 1] << std::endl;
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
