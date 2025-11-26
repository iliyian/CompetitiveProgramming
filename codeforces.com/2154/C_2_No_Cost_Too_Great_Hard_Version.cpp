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
 * @Author : iliyian
 * @File   : C_2_No_Cost_Too_Great_Hard_Version.cpp
 * @Time   : 2025-10-20 22:39:42
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::vector<int> minp, primes;

void sieve(int n) {
  minp.assign(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      primes.push_back(i);
    }
    for (int p : primes) {
      if (i * p > n) break;
      minp[i * p] = p;
      if (i % p == 0) break;
    }
  }
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::ranges::iota(p, 0);
  std::ranges::sort(p,
    [&](int i, int j) {
      return b[i] < b[j];
    }
  );
  std::set<int> s;
  bool ok = false;
  for (int i = 0; i < n && !ok; i++) {
    for (int x = a[i]; x > 1;) {
      int p = minp[x];
      while (x % p == 0) x /= p;
      if (s.count(p)) {
        ok = true;
        break;
      }
      s.insert(p);
    }
  }
  if (ok) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = b[p[0]] + b[p[1]];
  for (int i = 0; i < n; i++) {
    for (int x = a[i] + 1; x > 1; x /= minp[x]) {
      if (s.count(minp[x])) {
        ans = std::min(ans, b[i]);
        break;
      }
    }
  }
  for (int q : s) {
    int x = q - a[p[0]] % q;
    if (x == q) {
      continue;
    }
    ans = std::min(ans, x * b[p[0]]);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  sieve((int)2e5 + 2);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
