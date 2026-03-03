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
 * @File    : E_Decryption.cpp
 * @Time    : 2025-12-19 17:34:16
 * @Comment : 一道很奇怪的题
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p;
  int nn = n;
  for (int i = 2; i * i <= nn; i++) {
    if (nn % i == 0) {
      p.push_back(i);
      while (nn % i == 0) nn /= i;
    }
  }
  if (nn > 1) {
    p.push_back(nn);
  }
  if (p.size() == 2 && n == p.front() * p.back()) {
    for (auto i : p) {
      std::cout << i << ' ';
    }
    std::cout << n << ' ';
    std::cout << '\n' << 1 << '\n';
    return;
  }
  std::set<int> s;
  auto get = [&](int x) {
    std::vector<int> v;
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        v.push_back(i);
        if (i * i != x) {
          v.push_back(x / i);
        }
      }
    }
    std::ranges::sort(v);
    return v;
  };
  for (int i = 0; i < p.size(); i++) {
    auto v = get(n / p[i]);
    std::cout << p[i] << ' ';
    for (auto v : v) {
      if (i == p.size() - 1 || v != p[i + 1]) {
        if (s.count(v * p[i])) continue;
        s.insert(v * p[i]);
        std::cout << v * p[i] << ' ';
      }
    }
    if (i != p.size() - 1) {
      s.insert(p[i] * p[i + 1]);
      std::cout << p[i] * p[i + 1] << ' ';
    }
  }
  std::cout << n << '\n' << 0 << '\n';
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
