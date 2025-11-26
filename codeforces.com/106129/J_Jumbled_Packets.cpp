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
 * @File    : J_Jumbled_Packets.cpp
 * @Time    : 2025-11-03 12:16:32
 * @Comment : 这玩意确实跟交互题差别很大，像是构造的变种
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string op;
  std::cin >> op;
  if (op == "Encode") {
    int n;
    std::string s;
    std::cin >> n >> s;
    int pos = std::ranges::find(s, '1') - s.begin();
    if (pos == n) {
      std::cout << s << '\n';
      return;
    }
    for (int i = 0; i < n; i++) {
      std::cout << (i <= pos ? '2' : s[i]);
    }
  } else {
    int n;
    std::string s;
    std::cin >> n >> s;
    if (std::ranges::count(s, '2') == 0) {
      std::cout << s << '\n';
      return;
    }
    if (std::ranges::count(s, '2') == n) {
      std::cout << std::string(n - 1, '0') << 1 << '\n';
      return;
    }
    int pos;
    if (s.back() == '2') {
      pos = n - 1;
      while (pos >= 0 && s[pos] == '2') pos--;
      if (pos == -1) {
        std::cout << s;
        return;
      }
      pos++;
    } else {
      pos = 0;
      while (s[pos] != '2') pos++;
    }
    bool flag = true;
    for (int j = pos; (j + 1) % n != pos; j = (j + 1) % n) {
      if (s[(j + 1) % n] != '2') {
        if (flag) {
          std::cout << 1;
          flag = false;
        } else {
          std::cout << s[j];
        }
      } else {
        std::cout << 0;
      }
    }
    pos = (pos + n - 1) % n;
    std::cout << s[pos];
  }
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
