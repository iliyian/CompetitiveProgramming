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
 * @File    : F_Lisa_and_the_Martians.cpp
 * @Time    : 2025-12-26 19:20:00
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  std::vector<std::array<int, 2>> tr(n * k + 1);
  int tot = 1;
  int ans = a[1] & a[2], ansi = 1, ansj = 2, ansx = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::map<int, int> mp;
  auto insert = [&](int x) {
    int u = 1;
    int now = 0, nowx = 0;
    for (int i = k - 1; i >= 0; i--) {
      int idx = x >> i & 1;
      if (!tr[u][idx]) tr[u][idx] = ++tot;
      else {
        now ^= 1ll << i;
        nowx ^= (idx ^ 1) << i;
      }
      u = tr[u][idx];
    }
    int xval = ((1 << k) - 1) ^ now;
    if (now > ans) {
      ans = now;
      ansi = mp[xval], ansj = mp[x], ansx = nowx;
    }
  };
  for (int i = 1; i <= n; i++) {
    if (mp.count(a[i])) {
      std::cout << mp[a[i]] << ' ' << i << ' ' << 0 << '\n';
      return;
    }
    mp[a[i]] = i;
    insert(a[i]);
  }
  std::cout << ansi << ' ' << ansj << ' ' << ansx << '\n';
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
