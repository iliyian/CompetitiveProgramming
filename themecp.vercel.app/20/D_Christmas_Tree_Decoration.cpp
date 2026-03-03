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
 * @File    : D_Christmas_Tree_Decoration.cpp
 * @Time    : 2026-03-01 21:03:00
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1), a(n + 1);
  std::ranges::iota(p, 0);
  int s = 0;
  for (auto &i : a) std::cin >> i, s += i;
  std::sort(a.begin() + 1, a.end(), std::greater<>());
  int r = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[1]) {
      r = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] -= a[n];
  }
  auto check = [&](int idx) { // O(w)
    int need = idx - n;
    for (int i = 1; i <= n; i++) {
      need += a[r] - a[i];
    }
    return need <= a[0];
  };
  if (!check(r)) {
    std::cout << 0 << '\n';
    return;
  }
  auto A = [&](int n, int m) {
    int ans = 1;
    for (int i = n; i >= n - m + 1; i--) ans = ans * i % mod;
    return ans;
  };
  std::vector<int> fac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  int ans = 0;
  for (int i = r + 1; i <= n + 1; i++) {
    if (i == n + 1 || !check(i)) {
      ans = A(i - 1, r) * fac[n - r] % mod;
      std::cout << ans << '\n';
      return;
    }
  }


  // int ans = 0;
  // do {
  //   auto b = a;
  //   bool flag = true;
  //   for (int i = 1; i <= s; i++) {
  //     if (b[p[(i - 1) % n + 1]]) {
  //       b[p[(i - 1) % n + 1]]--;
  //     } else if (b[p[0]]) {
  //       b[p[0]]--;
  //     } else {
  //       flag = false;
  //       break;
  //     }
  //   }
  //   if (flag) {
  //     ans++;
  //     for (int i = 1; i <= n; i++) {
  //       std::cout << a[p[i]] << ' ';
  //     }
  //     std::cout << '\n';
  //   }
  // } while (std::next_permutation(p.begin() + 1, p.end()));
  // std::cout << ans << "\n\n";
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
