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
 * @File    : E.cpp
 * @Time    : 2026-02-25 14:17:40
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int ansx = 124142437, ansb = 243;

int getlen(int val) {
  int v = ansx + val;
  int l = 0;
  while (v) {
    v /= ansb;
    l++;
  }
  return l;
}

int ask(int d) {
  std::cout << "? " << d << std::endl;
  int ans;
  std::cin >> ans;
  // return getlen(d);
  return ans;
}

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  // int _x = ansx, _b = ansb;
  // while (_x) {
  //   _x /= _b;
  //   n++;
  // }
  int len0 = n, s0 = 0, s1 = 0;
  for (int i = 48; i >= 0; i--) {
    if (ask(s0 + (1ll << i)) == len0) {
      s0 |= 1ll << i;
    }
  }
  for (int i = 48; i >= 0; i--) {
    if (ask(s1 + (1ll << i)) == len0 + 1) {
      s1 |= 1ll << i;
    }
  }
  // std::cerr << s1 << ' ' << s0 << ' ' << s1 - s0 << '\n';
  int b = 2;
  while (qpow(b, len0) * (b - 1) < s1 - s0) {
    b++;
  }
  int x = qpow(b, len0) - 1 - s0;
  std::cout << "! " << x << ' ' << b << std::endl;
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
