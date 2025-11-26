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
 * @File    : D_Prefix_Permutation_Sums.cpp
 * @Time    : 2025-11-01 15:07:54
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n - 1), pre(n - 1);
  for (int i = 0; i < n - 1; i++) {
    std::cin >> a[i];
  }
  pre[0] = a[0];
  for (int i = 1; i < n - 1; i++) {
    pre[i] = a[i] - a[i - 1];
  }
  int sum = std::accumulate(pre.begin(), pre.end(), 0ll);
  std::vector<int> vis(n + 1);
  int s = 0;
  for (int i = 0; i < n - 1; i++) {
    if (pre[i] > n) {
      if (s == 0) s = pre[i];
      else {
        std::cout << "NO\n";
        return;
      }
      continue;
    }
    vis[pre[i]]++;
  }
  int s0 = 0, c = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      s0 += i;
      c++;
    }
    if (vis[i] == 2) {
      if (s == 0) s = i;
      else {
        std::cout << "NO\n";
        return;
      }
    }
  }
  if (c == 1) {
    std::cout << "YES\n";
    return;
  }
  if (s == 0 || c != 2) {
    std::cout << "NO\n";
    return;
  }
  std::cout << (s0 == s ? "YES" : "NO") << '\n';
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
