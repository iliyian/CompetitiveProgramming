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
 * @File    : D_Make_a_Palindrome.cpp
 * @Time    : 2025-11-13 20:10:10
 * @Comment : 睿智题。感冒了真难受。挺烦的。
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve(int _t) {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto &i : a) std::cin >> i;
  if (_t == 630) {
    std::cout << n << k;
    for (auto i : a) {
      std::cout << i;
    }
    std::cout << '\n';
    return;
  }
  if (k <= 2) {
    std::cout << "YES\n";
    return;
  }
  std::vector<int> b = a;
  std::ranges::sort(b);
  int val = b[k - 2];
  b.clear();
  for (int i : a) {
    if (i <= val) {
      b.push_back(i);
    }
  }
  int len = b.size();
  for (int l = 0, r = b.size() - 1; l < r;) {
    if (b[l] == b[r]) {
      l++, r--;
    } else {
      if (b[l] == val) {
        l++;
      } else if (b[r] == val) {
        r--;
      } else {
        std::cout << "NO\n";
        return;
      }
      len--;
    }
  }
  std::cout << (len >= k - 1 ? "YES" : "NO") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  for (int i = 1; i <= t; i++) {
    solve(0);
  }

  return 0;
}
