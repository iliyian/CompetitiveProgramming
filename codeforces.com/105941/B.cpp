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
 * @File   : B.cpp
 * @Time   : 2025-10-08 17:19:51
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

int qpow(int a, int b) {
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
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> f(n + 1);
  auto resize(n + 1);
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
  std::vector<std::vector<int>> ndp(n + 1, std::vector<int>(n + 1));
  std::vector<int> cnt(n + 1), s(n + 1), inv(n + 1);
  for (int i = 1; i <= n; i++) {
    inv[i] = qpow(i, mod - 2);
  }
  dp[0][1] = 1;
  for (int i = 0; i <= n; i++) {
    s[i] = 1;
  }
  int tot = 0;
  bool flag = false;
  int cnt1 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) {
      std::vector<int> ns(n + 1);
      for (int j = 0; j <= n; j++) {
        ndp[j][0] = ndp[j][1] = 0;
        for (int k = 2; k <= std::min(cnt[j], cnt1); k++) {
          ndp[j][k] = 0;
        }
      }
      for (int j = flag; j <= n; j++) {
        ndp[j][1] += (j == 0 ? 1 : s[j - 1]) * cnt[j] % mod * inv[tot] % mod;
        ndp[j][1] %= mod;
        ns[j] += ndp[j][1];
        ns[j] %= mod;
      }
      cnt1++;
      for (int j = 0; j <= n; j++) {
        for (int k = 2; k <= std::min(cnt[j], cnt1); k++) {
          ndp[j][k] += dp[j][k - 1] * (cnt[j] - (k - 1)) % mod * inv[tot] % mod;
          ndp[j][k] %= mod;
          ns[j] += ndp[j][k];
          ns[j] %= mod;
        }
      }
      for (int j = 1; j <= n; j++) {
        ns[j] += ns[j - 1];
        ns[j] %= mod;
      }
      tot--;
      flag = true;
      s = ns;
      dp.swap(ndp);
    } else {
      cnt[a[i]]++;
      tot++;
    }
  }
  std::cout << s[n] << '\n';
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