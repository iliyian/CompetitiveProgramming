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
 * @File    : E_Character_Blocking.cpp
 * @Time    : 2025-11-12 20:42:33
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;
int p[N + 1];

bool isprime(int x) {
  if (x < 2) return true;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int findPrime(int x) {
  while (!isprime(x)) x++;
  return x;
}

const int mod = findPrime((int)1e8 + 9e8);
const int base = 233;

void solve() {
  std::vector<std::string> s(2);
  for (int i = 0; i < 2; i++) {
    std::cin >> s[i];
  }
  int t, q;
  std::cin >> t >> q;
  std::vector<std::array<int, 3>> unblock(q + t + 1, {-1, -1, -1});
  auto replace = [&](int x, int s, int t, int &h) {
    h = h - p[x] * s % mod + mod;
    h %= mod;
    h = h + p[x] * t % mod;
    h %= mod;
  };
  int h[2] {};
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < s[t].size(); i++) {
      replace(i, 0, s[t][i], h[t]);
    }
  }
  for (int i = 1; i <= q; i++) {
    int op;
    std::cin >> op;
    auto u = unblock[i];
    if (u[2] != -1) {
      for (int t = 0; t < 2; t++) {
        replace(u[2], 0, s[t][u[2]], h[t]);
      }
    }
    if (op == 1) {
      int x;
      std::cin >> x;
      x--;
      unblock[i + t] = {s[0][x], s[1][x], x};
      for (int t = 0; t < 2; t++) {
        replace(x, s[t][x], 0, h[t]);
      }
    } else if (op == 2) {
      int x[2], ss[2], c[2];
      for (int i = 0; i < 2; i++) {
        std::cin >> ss[i] >> x[i];
        ss[i]--, x[i]--;
        c[i] = s[ss[i]][x[i]];
      }
      for (int i = 0; i < 2; i++) {
        replace(x[i], c[i], c[i ^ 1], h[ss[i]]);
        s[ss[i]][x[i]] = c[i ^ 1];
      }
    } else {
      std::cout << (h[0] == h[1] ? "YES" : "NO") << '\n';
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  p[0] = 1;
  for (int i = 1; i <= N; i++) {
    p[i] = p[i - 1] * base % mod;
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
