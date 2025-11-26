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
 * @File    : B.cpp
 * @Time    : 2025-10-31 14:32:51
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int inf = LLONG_MAX / 3;

std::vector<std::vector<int>> operator*(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) {
  int n = a.size();
  std::vector<std::vector<int>> c(n, std::vector<int>(n, -inf));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        c[i][j] = std::max(c[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return c;
}

std::vector<std::vector<int>> qpow(std::vector<std::vector<int>> a, int b) {
  int n = a.size();
  std::vector<std::vector<int>> ans(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    ans[i][i] = 0;
  }
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n, m, k, R;
  std::cin >> n >> m >> k >> R;
  std::vector<int> a(n), c(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i] >> c[i];
  }
  int mxS = 1 << n;
  std::vector<std::vector<int>> f(mxS, std::vector<int>(mxS, -inf));
  for (int i = 0; i < mxS; i++) {
    for (int j = 0; j < mxS; j++) {
      int sumc = 0, suma = 0;
      for (int l = 0; l < n; l++) {
        if (j >> l & 1) {
          sumc += (i >> l & 1) ? c[l] + k : c[l];
          suma += a[l];
        }
      }
      if (sumc <= m) {
        f[i][j] = suma;
      }
    }
  }

  std::vector<std::vector<int>> s(mxS, std::vector<int>(mxS, -inf));
  s[0][0] = 0;
  // s = s * f;
  s = s * qpow(f, R);

  // for (int i = 0; i < mxS; i++) {
  //   int suma = 0, sumc = 0;
  //   for (int j = 0; j < n; j++) {
  //     if (i >> j & 1) {
  //       suma += a[j];
  //       sumc += c[j];
  //     }
  //   }
  //   if (sumc <= m) {
  //     s[0][i] = suma;
  //   }
  // }
  // for (int i = 1; i < R; i++) {
  //   s = s * f;
  // }
  // std::vector<std::vector<std::vector<int>>> g(31);
  // g[0] = f;
  // for (int i = 1; i <= 30; i++) {
  //   g[i] = g[i - 1] * g[i - 1];
  // }
  // R--;
  // for (int i = 0; )
  //   if (R >> i & 1) {
  //     s = s * g[i];
  //   }
  // }

  // for (int i = 0; i < mxS; i++) {
  //   std::cerr << s[0][i] << ' ';
  // }
  // std::cerr << '\n';

  int ans = 0;
  for (int i = 0; i < mxS; i++) {
    ans = std::max(ans, s[0][i]);
  }
  std::cout << ans << '\n';
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
