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
 * @File    : D_2_Little_String_Hard_Version.cpp
 * @Time    : 2026-03-12 00:45:27
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;
constexpr int inv2 = 5e8 + 4;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string w;
  std::cin >> w;
  int ans = 1, ansk = 1;
  if (w.front() == '0' || w.back() == '0' || k == 1) {
    std::cout << -1 << '\n';
    return;
  }
  if (w.back() == '?') w.back() = '1';
  int cnt2 = 0;
  for (int i = 1; i < n; i++) {
    if (w[i] == '?') {
      if (i == 1) {
      } else {
        ans = ans * 2 % mod;
        ansk = ansk * 2 % k;
        cnt2++;
      }
    } else if (w[i] == '1') {
      ans = ans * 2 % mod;
      ansk = ansk * 2 % k;
      cnt2++;
    } else {
      ans = ans * i % mod;
      ansk = ansk * i % k;
      cnt2 += __builtin_ctzll(i);
    }
  }
  if (!ansk) {
    int cnt = cnt2 - __builtin_ctzll(k);
    for (int i = 3; i < n; i += 2) {
      if (w[i] == '?') {
        ans = ans * inv2 % mod * i % mod;
        if (--cnt == -1) {
          break;
        }
      }
    }
    if (cnt != -1) {
      ans = -1;
    }
  }
  std::cout << ans << '\n';
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
