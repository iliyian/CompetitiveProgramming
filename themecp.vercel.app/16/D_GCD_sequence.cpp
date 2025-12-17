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
 * @File    : D_GCD_sequence.cpp
 * @Time    : 2025-12-09 10:02:38
 * @Comment : 果然写之前得想好所有细节吗？
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> pre(n + 3), a(n + 2), ok(n + 2, 1), ok2(n + 3, 1), suf(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  pre[1] = pre[0] = 0;
  suf[n] = suf[n + 1] = LLONG_MAX / 3;
  for (int i = 2; i <= n; i++) {
    pre[i] = std::gcd(a[i - 1], a[i]);
  }
  for (int i = n - 1; i >= 1; i--) {
    suf[i] = std::gcd(a[i + 1], a[i]);
  }
  for (int i = 2; i <= n; i++) {
    ok[i] = ok[i - 1] & (pre[i - 1] <= pre[i]);
  }
  for (int i = n - 1; i >= 1; i--) {
    ok2[i] = ok2[i + 1] & (suf[i] <= suf[i + 1]);
  }
  if (ok[n - 1] || ok2[2]) {
    std::cout << "YES\n";
    return;
  }
  for (int i = 2; i <= n - 1; i++) {
    int g = std::gcd(a[i - 1], a[i + 1]);
    if (ok[i - 1] && ok2[i + 1] && pre[i - 1] <= g && g <= suf[i + 1]) {
      std::cout << "YES\n";
      return;
    }
  }
  std::cout << "NO\n";
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
