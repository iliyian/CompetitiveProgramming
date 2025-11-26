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
 * @File    : d.cpp
 * @Time    : 2025-10-31 16:25:30
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::vector<std::vector<int>> f(16, std::vector<int>(121, -1));

void solve() {
  int a, b, n, p;
  std::cin >> a >> b >> n >> p;
  auto check = [&](int cnt, int val) {
    if (val < 0 || val > 120 || cnt < 0 || cnt > 15) return 0;
    if (f[cnt][val] == -1) return 0;
    return 1;
  };
  auto print = [&](int cnt, int val, std::string &s) {
    // std::string s;
    for (int i = cnt; i > 0; i--) {
      if (f[i][val] == 1) {
        // std::cout << "1";
        s.push_back('1');
        s.push_back('/');
        s.push_back('/');
      } else {
        s.push_back('1');
        s.push_back(char(f[i][val] - 1 + '0'));
        // std::cout << "1" << f[i][val];
      }
      val -= f[i][val];
    }
    // return s;
  };
  int d = 21 - n;
  int q[] = {2, 3, 4, 5, 6, 7};
  for (int i = 0; i <= std::min(d, 15ll); i++) {
    for (int j = 0; j + i <= std::min(d, 15ll); j++) {
      int r = d - i - j;
      int a_need = a, b_need = b;
      r = std::max(r, 0ll);
      if (r > 6) continue;
      int mxS = 1 << r;
      if (i + j == 15) {
        for (int s = 0; s < mxS; s++) {
          a_need = a, b_need = b;
          for (int k = 0; k < r; k++) {
            if (s >> k & 1) {
              b_need -= q[k];
            } else {
              a_need -= q[k];
            }
          }
          if (check(i, a_need) && check(j, b_need)) {
            if (r == 6) {
              if ((s >> (r - 1) & 1) != p) {
                continue;
              }
            }
            std::string ans;
            print(i, a_need, ans);
            // std::cout << "/";
            ans.push_back('/');
            print(j, b_need, ans);
            int nowp = 1;
            for (int k = 0; k < r; k++) {
              if ((s >> k & 1) != nowp) {
                // std::cout << "/";
                ans.push_back('/');
                nowp ^= 1;
              }
              ans.push_back(char(q[k] + '0'));
            }
            if (nowp != p) {
              ans.push_back('/');
            }
            std::cout << ans;
            std::cout << '\n';
            return;
          }
        }
      } else {
        if (i + j != d) continue;
        if (check(i, a_need) && check(j, b_need)) {
          std::string ans;
          print(i, a_need, ans);
          ans.push_back('/');
          print(j, b_need, ans);
          int nowp = 1;
          if (nowp != p) {
            ans.push_back('/');
          }
          std::cout << ans;
          std::cout << '\n';
          return;
        }
      }
    }
  }
  std::cout << "NA\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  f[0][0] = 0;
  for (int i = 1; i <= 15; i++) {
    for (int j = 0; j <= 120; j++) {
      for (int k = 1; k <= std::min(8ll, j); k++) {
        if (k == 2) continue;
        if (f[i - 1][j - k] != -1) {
          f[i][j] = k;
        }
      }
    }
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
