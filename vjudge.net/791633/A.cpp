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
 * @File    : A.cpp
 * @Time    : 2026-02-23 11:45:23
 * @Comment : 哪个神仙能知道从pdf复制的负号不是真正的符号啊（（（
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int x[4] {}, y[4] {};
  for (int i = 0; i < 4; i++) {
    std::cin >> x[i] >> y[i];
  }
  long double x0, y0;
  int t;
  std::cin >> x0 >> y0 >> t;
  int i = 0;
  for (int s = 0; s < 4; s++) {
    if (y[s] < y[i]) {
      i = s;
    }
  }
  int j = (i + 1) % 4, k = (i + 3) % 4;
  auto cross = [&](long double x1, long double y1, long double x2, long double y2) {
    return x1 * y2 - x2 * y1;
  };
  long double theta = atan2l(y[k] - y[i], x[k] - x[i]);

  long double gj = std::abs(10 * sinl(theta));
  long double gk = std::abs(10 * cosl(theta));
  long double dj = std::abs(cross(x[j] - x[i], y[j] - y[i], x0 - x[i], y0 - y[i]) / sqrtl((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i])));
  long double dk = std::abs(cross(x[k] - x[i], y[k] - y[i], x0 - x[i], y0 - y[i]) / sqrtl((x[k] - x[i]) * (x[k] - x[i]) + (y[k] - y[i]) * (y[k] - y[i])));

  auto calc = [&](long double T) {
    long double _t = fmodl(t, T);
    _t = std::min(_t, T - _t);
    return _t;
  };
  
  auto getd = [&](long double t, long double a) {
    return 0.5 * a * t * t;
  };

  long double tj, tk, Tj, Tk, _tj, _tk, _dj = dj, _dk = dk;
  if (gj != 0) {
    tj = sqrtl(2 * dj / gj);
    Tj = tj * 2;
    _tj = calc(Tj);
    _dj = dj - getd(_tj, gj); // 相对于i的
  }
  if (gk != 0) {
    tk = sqrtl(2 * dk / gk);
    Tk = tk * 2;
    _tk = calc(Tk);
    _dk = dk - getd(_tk, gk);
  }

  long double ans_x = x[i] + cosl(theta) * _dj - sinl(theta) * _dk;
  long double ans_y = y[i] + sinl(theta) * _dj + cosl(theta) * _dk;

  std::cout << std::fixed << std::setprecision(20) << ans_x << ' ' << ans_y << '\n';
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
