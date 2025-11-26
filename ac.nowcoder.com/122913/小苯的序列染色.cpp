/*

LLLLLLLLLLL             IIIIIIIIIIYYYYYYY       YYYYYYYIIIIIIIIII AAA NNNNNNNN
NNNNNNNN L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I A:::A
N:::::::N       N::::::N L:::::::::L             I::::::::IY:::::Y
Y:::::YI::::::::I             A:::::A             N::::::::N      N::::::N
LL:::::::LL             II::::::IIY::::::Y     Y::::::YII::::::II A:::::::A
N:::::::::N     N::::::N L:::::L                 I::::I  YYY:::::Y   Y:::::YYY
I::::I             A:::::::::A           N::::::::::N    N::::::N L:::::L I::::I
Y:::::Y Y:::::Y     I::::I            A:::::A:::::A          N:::::::::::N
N::::::N L:::::L                 I::::I      Y:::::Y:::::Y      I::::I A:::::A
A:::::A         N:::::::N::::N  N::::::N L:::::L                 I::::I
Y:::::::::Y       I::::I          A:::::A   A:::::A        N::::::N N::::N
N::::::N L:::::L                 I::::I        Y:::::::Y        I::::I A:::::A
A:::::A       N::::::N  N::::N:::::::N L:::::L                 I::::I Y:::::Y
I::::I        A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N L:::::L I::::I
Y:::::Y         I::::I       A:::::::::::::::::::::A     N::::::N N::::::::::N
  L:::::L         LLLLLL  I::::I         Y:::::Y         I::::I
A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N
LL:::::::LLLLLLLLL:::::LII::::::II       Y:::::Y       II::::::II   A:::::A
A:::::A   N::::::N      N::::::::N L::::::::::::::::::::::LI::::::::I
YYYY:::::YYYY    I::::::::I  A:::::A               A:::::A  N::::::N N:::::::N
L::::::::::::::::::::::LI::::::::I    Y:::::::::::Y    I::::::::I A:::::A
A:::::A N::::::N        N::::::N LLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII
YYYYYYYYYYYYY    IIIIIIIIIIAAAAAAA                   AAAAAAANNNNNNNN NNNNNNN

 *
 * ==============================================================================
 * @Author  : iliyian
 * @File    : 小苯的序列染色.cpp
 * @Time    : 2025-11-26 18:06:20
 * @Comment :
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), minl(n + 1, n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int l = i - a[i] + 1, r = i + a[i] - 1;
    if (l >= 1 && a[i] >= a[l]) {
      minl[i] = std::min(minl[i], l);
    }
    if (r <= n && a[i] >= a[r]) {
      minl[r] = std::min(minl[r], i);
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    minl[i] = std::min(minl[i], minl[i + 1]);
    if (minl[i] > i) {
      minl[i] = n + 1;
    }
  }
  int p = n, ans = 0;
  while (p) {
    if (minl[p] == n + 1) {
      std::cout << -1 << '\n';
      return;
    }
    p = minl[p] - 1;
    ans++;
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
