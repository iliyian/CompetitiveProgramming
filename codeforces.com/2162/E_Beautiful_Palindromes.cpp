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
 * @File   : E_Beautiful_Palindromes.cpp
 * @Time   : 2025-10-17 22:55:45
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

bool isprime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int getprime(int x) {
  while (!isprime(x)) x++;
  return x;
}

int base = 233, mod = getprime(rd() % (int)1e8 + (int)9e8);

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n), p(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
  }
  p[0] = 1;
  for (int i = 0; i < n; i++) {
    p[i + 1] = p[i] * base % mod;
  }
  auto calc = [&](std::vector<int> a) {
    std::vector<int> h(n + 1);
    for (int i = 0; i < n; i++) {
      h[i + 1] = h[i] * base % mod + a[i];
      h[i + 1] %= mod;
    }
    return h;
  };
  auto get = [&](int l, int r, std::vector<int> &h) {
    return (h[r] + (mod - h[l]) * p[r - l]) % mod;
  };
  auto h = calc(a);
  auto b = a;
  std::ranges::reverse(b);
  auto g = calc(b);
  int x[3] = {0, 0, 0};
  std::set<int> s;
  s.insert(a[n - 1]);
  for (int i = n - 1; i >= 1; i--) {
    if (get(i, n, h) == get(0, n - i, g)) {
      s.insert(a[i - 1]);
    }
  }
  while (s.contains(x[0])) {
    x[0]++;
  }
  // std::cerr << x[0] + 1 << '\n';
  int u = a[n - 1], v = x[0];
  for (int i = 1; i < 3; i++) {
    while (x[i] == u || x[i] == v) {
      x[i]++;
    }
    u = v;
    v = x[i];
  }
  for (int i = 0; i < k; i++) {
    std::cout << x[i % 3] + 1 << ' ';
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
