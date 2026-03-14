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
 * @File    : E_The_Robotic_Rush.cpp
 * @Time    : 2026-03-05 21:05:10
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n), b(m + 2);
  for (auto &i : a) std::cin >> i;
  b[0] = LLONG_MIN / 3, b[m + 1] = LLONG_MAX / 3;
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  std::ranges::sort(b.begin() + 1, b.begin() + m + 1);
  std::string s;
  std::cin >> s;
  int now = 0;
  std::vector<int> l(k + 1), r(k + 1);
  for (int i = 0; i < k; i++) {
    if (s[i] == 'L') now--;
    else now++;
    l[i + 1] = l[i], r[i + 1] = r[i];
    l[i + 1] = std::min(l[i + 1], now);
    r[i + 1] = std::max(r[i + 1], now);
  }
  for (auto &i : l) i = -i;
  std::vector<int> ans(k + 2);
  int j = 0;
  for (auto i : a) {
    auto p = std::ranges::upper_bound(b, i) - b.begin();
    int ldis = i - b[p - 1], rdis = b[p] - i;
    auto pl = std::ranges::lower_bound(l, ldis) - l.begin();
    auto pr = std::ranges::lower_bound(r, rdis) - r.begin();
    ans[std::min(pl, pr) - 1]++;
  }
  for (int i = k; i >= 1; i--) {
    ans[i] += ans[i + 1];
  }
  for (int i = 1; i <= k; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
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
