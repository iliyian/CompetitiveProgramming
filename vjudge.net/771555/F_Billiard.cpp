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
 * @File    : F_Billiard.cpp
 * @Time    : 2025-12-16 18:49:49
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

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
  if (a < 0) { // 负数特判，但是没用经过例题测试
    a = -a;
    u = -1;
  }
  if (b < 0) {
    b = -b;
    v = -1;
  }
  int x, y, d = exgcd(a, b, x, y), ans;
  if (c % d != 0) { // 无整数解
    return {LLONG_MIN, LLONG_MIN};
  }
  a /= d, b /= d, c /= d;
  x *= c, y *= c; // 得到可行解
  ans = (x % b + b - 1) % b + 1;
  auto [A, B] = pair{u * ans, v * (c - ans * a) / b}; // x最小正整数 特解
  ans = (y % a + a - 1) % a + 1;
  // auto [C, D] = pair{u * (c - ans * b) / a, v * ans}; // y最小正整数 特解
  // int num = (C - A) / b + 1; // xy均为正整数 的 解的组数
  return {A, B};
}

void solve() {
  int n, m, x, y, vx, vy;
  std::cin >> n >> m >> x >> y >> vx >> vy;
  if (vx == 0) {
    if (x % n == 0) {
      if (vy > 0) {
        std::cout << x << ' ' << m << '\n';
      } else {
        std::cout << x << ' ' << 0 << '\n';
      }
      return;
    }
    std::cout << -1 << '\n';
    return;
  }
  int A = n * vy, B = -m * vx, C = x * vy - y * vx;
  auto [k1, k2] = calc(A, B, C);
  if (k1 == LLONG_MIN) {
    std::cout << -1 << '\n';
    return;
  }
  int d = std::abs(std::gcd(A, B));
  int step = std::abs(B) / d;

  int _k1 = k1;
  k1 = (k1 % step + step) % step;
  std::cerr << A << ' ' << B << ' ' << d << ' ' << k1 << ' ' << k2 << ' ' << (k1 * n - x) / vx << ' ' << step << '\n';
  if (vx > 0) {
    while (k1 * n - x < 0) k1 += step;
  } else {
    while (k1 * n - x > 0) k1 -= step;
  }

  k2 = k2 - (k1 - _k1) * (A / d);

  std::cout << (k1 % 2 == 0 ? 0 : n) << ' ' << (k2 % 2 == 0 ? 0 : m) << '\n';
  std::cerr << (k1 * n - x) / vx << '\n';
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
