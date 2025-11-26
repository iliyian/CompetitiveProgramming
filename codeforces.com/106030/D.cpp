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
 * @Author : iliyian
 * @File   : J.cpp
 * @Time   : 2025-10-22 17:37:47
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

std::pair<int, int> calc(int a, int b, int c) {
  int u = 1, v = 1;
  if (a < 0) {
    a = -a;
    u = -1;
  }
  if (b < 0) {
    b = -b;
    v = -1;
  }
  int x, y, d = exgcd(a, b, x, y), ans;
  if (c % d != 0) {
    return {-1, -1};
  }
  a /= d, b /= d, c /= d;
  x *= c, y *= c;
  ans = (x % b + b - 1) % b + 1;
  return {u * ans, v * (c - ans * a) / b};
}

std::vector<int> prod;

void solve() {
  int a, b;
  std::cin >> a >> b;
  int v = 1;
  while (b % 2 == 0) {
    b /= 2;
    v *= 2;
  }
  while (b % 5 == 0) {
    b /= 5;
    v *= 5;
  }
  if (b == 1) {
    std::cout << 0 << ' ' << 1 << '\n';
    return;
  }
  int w = b;
  b *= v;
  int ansc = INT_MAX, ansd = INT_MAX;
  for (int i : prod) {
    int d = i * w;
    if (d > 1000000000) break;
    auto [c, what] = calc(b / w, - w, - a * i);
    if (c > 0) {
      if (c < ansc) {
        ansc = c;
        ansd = d;
      }
    }
  }
  std::cout << ansc << ' ' << ansd << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int p2 = 1;
  for (int i = 0; i < 50; i++, p2 *= 2) {
    int p5 = 1;
    for (int j = 0; j < 50; j++, p5 *= 5) {
      if (p2 * p5 < INT_MAX) {
        prod.push_back(p2 * p5);
      } else {
        break;
      }
    }
  }
  std::ranges::sort(prod);
  // std::cerr << prod.size() << '\n';

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
