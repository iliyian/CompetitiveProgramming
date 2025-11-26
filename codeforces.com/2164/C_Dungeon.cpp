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
 * @File    : C_Dungeon.cpp
 * @Time    : 2025-11-06 23:03:46
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> b(m), c(m), p;
  std::multiset<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    a.insert(x);
  }
  for (int i = 0; i < m; i++) {
    std::cin >> b[i];
  }
  std::vector<int> v;
  for (int i = 0; i < m; i++) {
    std::cin >> c[i];
    if (c[i]) {
      p.push_back(i);
    } else {
      v.push_back(i);
    }
  }
  std::ranges::sort(p, [&](auto x, auto y) {
    return b[x] < b[y];
  });
  int ans = 0;
  for (int i = 0; i < p.size(); i++) {
    auto q = a.lower_bound(b[p[i]]);
    if (q == a.end()) {
    } else {
      int cura = *q;
      a.erase(q);
      a.insert(std::max(cura, c[p[i]]));
      ans++;
    }
  }
  std::ranges::sort(v, [&](auto x, auto y) {
    return b[x] < b[y];
  });
  for (int i = 0; i < v.size(); i++) {
    auto q = a.lower_bound(b[v[i]]);
    if (q != a.end()) {
      a.erase(q);
      ans++;
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
