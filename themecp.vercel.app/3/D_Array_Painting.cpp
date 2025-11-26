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
 * @File    : D_Array_Painting.cpp
 * @Time    : 2025-11-16 11:57:47
 * @Comment : 屎题，跟状态机一样
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> b;
  int pre = 0, ans = 0, has0 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      if (pre) {
        b.push_back(pre);
        pre = 0;
      }
      b.push_back(0);
    } else {
      pre = std::max(pre, a[i]);
    }
  }
  if (pre) {
    b.push_back(pre);
  }
  pre = 0;
  // for (int i = 1; i <= n; i++) {
  for (auto val : b) {
    if (val == 0) {
      if (has0) { // 上一个0必然不可以了
        pre = 0;
        ans++;
        continue;
      }
      if (pre == 0) { // 作为堆积的0
        has0 = 1;
      } else { // 否则前面有1或者2
        if (pre == 1 || pre == 2) {
          ans++;
        }
      }
      pre = 0;
    } else if (val == 1) {
      if (has0) {
        ans++;
        has0 = 0;
      } else {
        if (pre == 0) {
          pre = 1;
        }
      }
    } else {
      if (has0) {
        ans++;
        has0 = 0;
        pre = 3;
      } else {
        if (pre < 2) {
          pre = 2;
        }
      }
    }
  }
  if (has0 || pre == 1 || pre == 2) {
    ans++;
  }
  std::cout << ans << '\n';
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
