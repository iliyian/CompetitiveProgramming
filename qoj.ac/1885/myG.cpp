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
 * @Author : iliyian
 * @File   : myG.cpp
 * @Time   : 2025-10-27 21:23:05
 * ==============================================================================
*/

#include <bits/stdc++.h>

constexpr int N = 1e6;
std::vector<std::vector<int>> fac(N + 1);
std::vector<std::array<int, 26>> tr(2 * N);
std::vector<int> cnt(N * 2);

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::vector<int> f(n + 1);
  int tot = 1, ans = 0;
  tr[1].fill(0);
  for (int i = 0; i < n; i++) {
    std::cin >> s;
    int p = 1;
    for (int j = 0; j < s.size(); j++) {
      if (!tr[p][s[j] - 'a']) {
        tr[p][s[j] - 'a'] = ++tot;
        tr[tot].fill(0);
        cnt[tot] = 0;
      }
      p = tr[p][s[j] - 'a'];
      cnt[p]++;
      for (auto p : fac[cnt[p]]) {
        ans ^= f[p] * p;
        f[p]++;
        ans ^= f[p] * p;
      }
    }
    std::cout << ans << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
