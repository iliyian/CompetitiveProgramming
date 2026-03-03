/*

LLLLLLLLLLL       IIIIIIIIIIYYYYYYY     YYYYYYYIIIIIIIIII         AAA         NNNNNNNN    NNNNNNNN
L:::::::::L       I::::::::IY:::::Y     Y:::::YI::::::::I        A:::A        N:::::::N     N::::::N
L:::::::::L       I::::::::IY:::::Y     Y:::::YI::::::::I       A:::::A       N::::::::N    N::::::N
LL:::::::LL       II::::::IIY::::::Y   Y::::::YII::::::II      A:::::::A      N:::::::::N   N::::::N
  L:::::L         I::::I  YYY:::::Y   Y:::::YYY  I::::I       A:::::::::A       N::::::::::N  N::::::N
  L:::::L         I::::I   Y:::::Y Y:::::Y   I::::I      A:::::A:::::A      N:::::::::::N   N::::::N
  L:::::L         I::::I    Y:::::Y:::::Y    I::::I       A:::::A A:::::A     N:::::::N::::N  N::::::N
  L:::::L         I::::I     Y:::::::::Y     I::::I      A:::::A   A:::::A    N::::::N N::::N N::::::N
  L:::::L         I::::I    Y:::::::Y    I::::I     A:::::A   A:::::A     N::::::N  N::::N:::::::N
  L:::::L         I::::I     Y:::::Y     I::::I    A:::::AAAAAAAAA:::::A    N::::::N   N:::::::::::N
  L:::::L         I::::I     Y:::::Y     I::::I     A:::::::::::::::::::::A   N::::::N  N::::::::::N
  L:::::L     LLLLLL  I::::I     Y:::::Y     I::::I    A:::::AAAAAAAAAAAAA:::::A  N::::::N   N:::::::::N
LL:::::::LLLLLLLLL:::::LII::::::II     Y:::::Y     II::::::II   A:::::A       A:::::A   N::::::N    N::::::::N
L::::::::::::::::::::::LI::::::::I  YYYY:::::YYYY  I::::::::I  A:::::A         A:::::A  N::::::N     N:::::::N
L::::::::::::::::::::::LI::::::::I  Y:::::::::::Y  I::::::::I A:::::A         A:::::A N::::::N    N::::::N
LLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII  YYYYYYYYYYYYY  IIIIIIIIIIAAAAAAA           AAAAAAANNNNNNNN     NNNNNNN

 * 
 * ==============================================================================
 * @Author  : iliyian
 * @File  : 东风谷早苗与博丽灵梦.cpp
 * @Time  : 2026-02-09 15:27:05
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int __int128
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

using i64 = long long;

void print(int x) {
  if (x < 10) {
    std::cout << char(x + '0');
    return;
  }
  print(x / 10);
  std::cout << char(x % 10 + '0');
}

void solve() {
  i64 c, a, b;
  std::cin >> c >> a >> b;

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
    cout << "No" << '\n';
    return;
  }
  a /= d, b /= d, c /= d;
  x *= c, y *= c; // 得到可行解

  // ans = (x % b + b - 1) % b + 1;
  ans = (x % b + b) % b;
  auto [A, B] = pair{u * ans, v * (c - ans * a) / b}; // x最小非负整数整数 特解

  // ans = (y % a + a - 1) % a + 1;
  ans = (y % a + a) % a;
  auto [C, D] = pair{u * (c - ans * b) / a, v * ans}; // y最小非负整数整数 特解

  int num = (C - A) / b + 1; // xy均为非负整数整数 的 解的组数

  // std::cerr << A << ' ' << B << '\n';
  // std::cerr << C << ' ' << D << '\n';
  // std::cerr << num << '\n';

  if (num <= 0) {
    std::cout << "No" << '\n';
    return;
  }

  int l = 0, r = num - 1, _ans = LLONG_MIN / 3;
  while (l <= r) {
    int mid = (l + r) / 2;
    int x = A + mid * b, y = (c - a * x) / b;
    if (x <= y) l = mid + 1, _ans = mid;
    else r = mid - 1;
  }
  int ansx = A, ansy = B;
  auto upd = [&](int mid) {
    int x = A + mid * b, y = (c - a * x) / b;
    if (std::max(ansx, ansy) > std::max(x, y)) {
      ansx = x, ansy = y;
    }
  };
  if (_ans >= 0 && _ans <= num - 1) {
    upd(_ans);
  }
  if (_ans + 1 >= 0 && _ans + 1 <= num - 1) {
    upd(_ans + 1);
  }
  upd(0);
  upd(num - 1);
  std::cout << "Yes\n";
  print(ansx);
  std::cout << ' ';
  print(ansy);
  std::cout << '\n';
  // std::cout << ansx << ' ' << ansy << '\n';

  // std::cout << "Yes\n";
  // // // int
  // for (int x = A; x <= C; x += b) {
  //   std::cerr << x << ' ';
  //   int y = (c - a * x) / b;
  //   std::cerr << y << '\n';
  //   // std::cout << a * x + b * y << ' ' << c << '\n';
  // }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  i64 t = 1;
  std::cin >> t;

  while (t--) {
  solve();
  }

  return 0;
}
