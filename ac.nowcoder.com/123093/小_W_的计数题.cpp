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
 * @File    : 小_W_的计数题.cpp
 * @Time    : 2025-12-07 10:43:48
 * @Comment : 
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
  std::stack<int> s;
  std::vector<int> pre(n + 2), suf(n + 2), r(n + 1), l(n + 1);
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] <= a[i]) {
      r[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    r[s.top()] = n + 1; s.pop();
  }
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] <= a[i]) {
      l[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  for (int i = n; i >= 1; i--) {
    pre[i] = pre[r[i]] + 1;
  }
  for (int i = 1; i <= n; i++) {
    suf[i] = suf[l[i]] + 1;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << pre[i] + suf[i] - 1 << ' ';
  }
  std::cout << '\n';

  // for (int i = 1; i <= n; i++) {
  //   std::cerr << l[i] << ' ';
  // }
  // std::cerr << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << r[i] << ' ';
  // }
  // std::cerr << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << pre[i] << ' ';
  // }
  // std::cerr << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << suf[i] << ' ';
  // }
  // std::cerr << '\n';
  // std::cout << '\n';
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
