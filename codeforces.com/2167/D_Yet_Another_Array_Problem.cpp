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
 * @File    : D_Yet_Another_Array_Problem.cpp
 * @Time    : 2025-10-29 18:12:12
 * @Comment : O(n\omega(V)) ?
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::vector<int> primes, minp;

void sieve(int N) {
  minp.assign(N + 1, 0);
  for (int i = 2; i <= N; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      primes.push_back(i);
    }
    for (int p : primes) { 
      if (i * p > N) break;
      minp[i * p] = p;
      if (i % p == 0) break;
    }
  }
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) std::cin >> i;
  for (int p : primes) { // likely o(logv) ?
    for (auto i : a) {
      if (i % p) {
        std::cout << p << '\n';
        return;
      }
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  sieve(10000000);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
