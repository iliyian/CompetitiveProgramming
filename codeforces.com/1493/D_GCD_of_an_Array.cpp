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
 * @File   : D_GCD_of_an_Array.cpp
 * @Time   : 2025-10-16 20:19:21
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::vector<int> minp, primes;

void sieve(int n) {
  minp.assign(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      primes.push_back(i);
      minp[i] = i;
    }
    for (int p : primes) {
      if (i * p > n) break;
      minp[i * p] = p;
      if (i % p == 0) break;
    }
  }
}

constexpr int N = 2e5, mod = 1e9 + 7;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int inv(int v) {
  return qpow(v, mod - 2);
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  std::vector<std::multiset<int>> v(N + 1);
  std::vector<std::set<std::pair<int, int>>> has(n);
  int ans = 1;
  auto del = [&](int x, int p) {
    ans = ans * inv(qpow(x, *v[x].begin())) % mod;
    v[x].erase(v[x].find(p));
    if (!v[x].empty()) {
      ans = ans * qpow(x, *v[x].begin()) % mod;
    }
  };
  auto add = [&](int x, int p) {
    if (!v[x].empty()) {
      ans = ans * inv(qpow(x, *v[x].begin())) % mod;
    }
    v[x].insert(p);
    ans = ans * qpow(x, *v[x].begin()) % mod;
  };
  int has1 = false;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (a[i] == 1) {
      has1 = true;
    }
    int x = a[i];
    while (x != 1) {
      int y = minp[x], cnt = 0;
      while (minp[x] == y) {
        cnt++;
        x /= y;
      }
      has[i].insert({y, cnt});
      add(y, cnt);
    }
  }
  std::cerr << ans << '\n';
  while (q--) {
    int i, x;
    std::cin >> i >> x;
    i--;
    if (a[i] == 1 && x != 1) {
      has1 = false;
    }
    while (x != 1) {
      int y = minp[x], cnt = 0;
      while (minp[x] == y) {
        cnt++;
        x /= y;
      }
      auto p = has[i].lower_bound({y, 0});
      if (p == has[i].end() || p->first != y) {
        has[i].insert({y, cnt});
        add(y, cnt);
      } else {
        int oldcnt = p->second;
        has[i].erase(p);
        has[i].insert({y, oldcnt});
        del(y, oldcnt);
        add(y, cnt);
      }
    }
    a[i] = x;
    std::cout << (has1 ? 1 : ans) << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  sieve(2e5);
  std::cerr << primes.size() << '\n';

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
