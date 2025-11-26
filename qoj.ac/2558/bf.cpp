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
 * @File    : bf.cpp
 * @Time    : 2025-11-05 21:15:10
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#include <random>
#define int long long

std::vector<int> solve(int n, std::vector<int> t, std::vector<int> a) {
  std::vector<int> solved(n + 1), ans(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] *= 2;
  }
  int tm = 1;
  while (1) {
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (!solved[i]) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      break;
    }
    for (int i = 1; i <= n; i++) {
      if (solved[i]) continue;
      if (a[t[i]] > a[i]) {
        a[i]++;
      } else if (a[t[i]] < a[i]) {
        a[i]--;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!solved[i] && a[i] == a[t[i]]) {
        solved[i] = 1;
        ans[i] = tm;
      }
    }
    tm++;
  }
  return ans;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937_64 rd(std::random_device{}());
  while (1) {
    int n = 500000, w = 1e9;
    std::ofstream os("d.in");
    os << n << '\n';
    std::vector<int> t(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
      t[i] = rd() % n + 1;
      while (t[i] == i) {
        t[i] = rd() % n + 1;
      }
      os << t[i] << ' ';
    }
    os << '\n';
    for (int i = 1; i <= n; i++) {
      a[i] = rd() % w - w / 2;
      while (std::find(a.begin() + 1, a.begin() + i, a[i]) != a.begin() + i) {
        a[i] = rd() % w - w / 2;
      }
      os << a[i] << ' ';
    }
    os << std::endl;
  //   // auto ans = solve(10, {0, 8,3,6,7,1,8,2,10,8,1}, {0, 0,-14,5,-3,14,-12,11,8,-18,17});
  //   auto ans = solve(3, {0, 2, 3, 1}, {0, -1, 2, 3});
    system("ok.exe");
    return 0;
    auto ans = solve(n, t, a);
    std::ifstream is("d.out");
    for (int i = 1; i <= n; i++) {
      int x;
      is >> x;
      if (ans[i] != x) {
        std::cout << "gg\n";
        std::cout << n << '\n';
        for (int i = 1; i <= n; i++) {
          std::cout << t[i] << ' ';
        }
        std::cout << '\n';
        for (int i = 1; i <= n; i++) {
          std::cout << a[i] << ' ';
        }
        std::cout << '\n';
        std::cout << "expected: \n";
        for (auto i = 1; i <= n; i++) {
          std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
        return 0;
      }
    }
  }

  return 0;
}
