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
 * @File    : 质数变化.cpp
 * @Time    : 2025-11-30 13:34:44
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::vector<int> minp, primes, id;
constexpr int N = 10000;

int dis[1300][1300] {};

void solve() {
  int s, t;
  std::cin >> s >> t;
  std::cout << dis[id[s]][id[t]] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  minp.assign(N + 1, 0);
  id.assign(N + 1, 0);
  for (int i = 2; i <= N; i++) {
    if (!minp[i]) {
      minp[i] = i;
      id[i] = primes.size();
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (i * p > N) break;
      minp[i * p] = p;
      if (i % p == 0) break;
    }
  }
  int ten[] = {1, 10, 100, 1000};
  for (int s = 0; s < primes.size(); s++) {
    std::queue<int> q;
    q.push(s);
    dis[s][s] = 0;
    while (!q.empty()) {
      int uu = q.front(); q.pop();
      int u = primes[uu];
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= 9; j++) {
          int v = (u - u / ten[i] % 10 * ten[i]) + j * ten[i];
          if (minp[v] == v && v > 1) {
            int vv = id[v];
            if (dis[s][vv] == 0 && vv != s) {
              dis[s][vv] = dis[s][uu] + 1;
              q.push(vv);
            }
          }
        }
      }
    }
  }
  // std::cerr << primes.size() << '\n';

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
