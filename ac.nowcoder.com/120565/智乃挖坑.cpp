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
 * @File    : 智乃挖坑.cpp
 * @Time    : 2026-02-11 17:18:45
 * @Comment : tmd想半天线段树
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, h;
  std::cin >> n >> m >> h;
  std::vector<int> p(m + 1), f(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> p[i] >> f[i];
  }
  auto check = [&](int mid) -> bool {
    std::vector<int> s(n + 2), s0(n + 2);
    for (int i = 1; i <= mid; i++) {
      if (p[i] < f[i]) {
        s0[0] += f[i] - p[i];
        // s0[std::min(n + 1, f[i] + p[i] - 1)] -= 1;
      }
      s[std::max(1ll, p[i] - f[i] + 1)]++;
      s[p[i] + 1]--;
      s[p[i] + 1]--;
      s[std::min(n + 1, p[i] + f[i] + 1)]++;
    }
    for (int i = 1; i <= n; i++) {
      s[i] += s[i - 1];
    }
    for (int i = 1; i <= n; i++) {
      s[i] = s[i] + s0[i - 1] + s[i - 1];
      // std::cerr << s[i] << ' ';
      // if (s[i] > h) {
      //   return true;
      // }
    }
    // std::cerr << '\n';
    for (int i = 1; i <= n; i++) {
      if (s[i] > h) {
        return true;
      }
    }
    return false;
  };
  int l = 1, r = m, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  if (ans == -1) {
    std::cout << "No\n";
    return;
  }
  std::cout << "Yes\n";
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
