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
 * @File    : G_The_Great_Equalizer.cpp
 * @Time    : 2026-03-09 15:54:09
 * @Comment : 一如既往的屎
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::multiset<int> s, d;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s.insert(a[i]);
  }
  auto b = a;
  std::sort(b.begin() + 1, b.end());
  for (int i = 2; i <= n; i++) {
    d.insert(b[i] - b[i - 1]);
  }
  auto del = [&](int val) {
    auto p = s.find(val);
    if (p != s.begin() && std::next(p) != s.end()) {
      d.erase(d.find(*p - *std::prev(p)));
      d.erase(d.find(*std::next(p) - *p));
      d.insert(*std::next(p) - *std::prev(p));
    } else if (p == s.begin()) {
      d.erase(d.find(*std::next(p) - *p));
    } else {
      d.erase(d.find(*p - *std::prev(p)));
    }
    s.erase(p);
  };
  auto add = [&](int val) {
    auto p = s.lower_bound(val);
    if (p != s.begin()) {
      d.insert(val - *std::prev(p));
    }
    if (p != s.end()) {
      d.insert(*p - val);
    }
    if (p != s.begin() && p != s.end()) {
      d.erase(d.find(*p - *std::prev(p)));
    }
    s.insert(val);
  };
  int q;
  std::cin >> q;
  while (q--) {
    int x, v;
    std::cin >> x >> v;
    if (n == 1) {
      std::cout << v << ' ';
      continue;
    }
    del(a[x]);
    a[x] = v;
    add(a[x]);
    std::cout << *s.rbegin() + *d.rbegin() << ' ';
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
