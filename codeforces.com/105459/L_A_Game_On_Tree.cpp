// date: 2025-10-27 15:46:22
// tag: 有意思的树上计数

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
 * @File   : L_A_Game_On_Tree.cpp
 * @Time   : 2025-10-26 11:12:40
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

int qpow(int a, int b = mod - 2) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = 0;
  std::vector<int> siz(n + 1), sum(n + 1);
  [&](this auto &&self, int u, int p) -> void {
    siz[u] = 1;
    int pre = 0;
    for (int v : g[u]) {
      if (v != p) {
        self(v, u);

        ans += (n - siz[v]) * (n - siz[v]) % mod * siz[v] % mod * siz[v] % mod;
        ans %= mod;

        ans += 2 * (n - siz[v]) * (n - siz[v]) % mod * ((sum[v] - siz[v] * siz[v] % mod + mod) % mod) % mod;
        ans %= mod;

        siz[u] += siz[v];
        
        ans += sum[u] * sum[v] % mod * 2 % mod;
        ans %= mod;

        sum[u] += sum[v];
        sum[u] %= mod;
      }
    }
    sum[u] += siz[u] * siz[u] % mod;
    sum[u] %= mod;
  } (1, 0);
  std::cout << ans * qpow((n * (n - 1) / 2) % mod * (n * (n - 1) / 2) % mod) % mod << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << sum[i] << ' ';
  // }
  // std::cerr << '\n';
  // std::cout << ans << '\n';
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
