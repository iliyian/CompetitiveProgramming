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
 * @File    : D_Inversion_Value_of_a_Permutation.cpp
 * @Time    : 2025-10-07 02:04:56
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

std::vector<int> p, val;
std::vector<int> f(1001, LLONG_MAX / 3), prv(1001, -1);

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> decompose;
  k = n * (n - 1) / 2 - k;
  if (k == 0) {
    for (int i = n; i >= 1; i--) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
    return;
  }
  while (k) {
    int len = k - prv[k];
    auto pt = std::ranges::lower_bound(p, len) - p.begin();
    k = prv[k];
    decompose.push_back(val[pt]);
    // auto pt = std::ranges::upper_bound(p, k) - p.begin() - 1;
    // k -= p[pt];
    // decompose.push_back(val[pt]);
  }
  std::vector<int> ans;
  int tot = 0;
  for (int len : decompose) {
    // std::cerr << len << '\n';
    tot += len;
    for (int i = tot; i >= tot - len + 1; i--) {
      ans.push_back(i);
    }
  }
  for (int i = tot + 1; i <= n; i++) {
    ans.push_back(i);
  }
  if (tot > n) {
    std::cout << 0 << '\n';
    return;
  }
  std::ranges::reverse(ans);
  for (int i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // freopen("d.in", "r", stdin);
  // freopen("d.out", "w", stdout);

  p.push_back(0);
  p.push_back(0);
  val.push_back(0);
  val.push_back(0);
  for (int i = 2; i <= 50; i++) {
    p.push_back(i * (i - 1) / 2);
    val.push_back(i);
  }

  f[0] = 0;
  for (int i = 1; i <= 1000; i++) {
    for (int j = 2; p[j] <= i; j++) {
      if (f[i] > f[i - p[j]] + j) {
        f[i] = f[i - p[j]] + j;
        prv[i] = i - p[j];
      }
    }
  }

  // for (int n = 2; n <= 8; n++) {
  //   std::vector<int> p(n + 1);
  //   std::ranges::iota(p, 0);
  //   std::reverse(p.begin() + 1, p.end());
  //   std::map<int, std::vector<int>> mp;
  //   // std::map<int, std::vector<std::vector<int>>> mp;
  //   do {
  //     int ans = 0;
  //     for (int l = 1; l <= n; l++) {
  //       bool f = false;
  //       for (int r = l + 1; r <= n; r++) {
  //         if (!f) {
  //           for (int i = l; i < r; i++) {
  //             if (p[i] > p[r]) {
  //               f = true;
  //               break;
  //             }
  //           }
  //         }
  //         if (f) {
  //           ans++;
  //         }
  //       }
  //     }
  //     // for (int i = 1; i <= n; i++) {
  //     //   std::cout << p[i] << ' ';
  //     // }
  //     // std::cout << " = " << ans << '\n';
  //     if (!mp.count(ans)) {
  //       mp[ans] = p;
  //     }
  //   } while (std::next_permutation(p.begin() + 1, p.end(), std::greater<>()));
  //   for (int i = 0; i <= n * (n - 2) / 2; i++) {
  //     if (!mp.count(i)) {
  //       std::cout << 0 << '\n';
  //       continue;
  //     }
  //     auto &vv = mp[i];
  //     // std::cout << k << " = ";
  //     for (int i = 1; i <= n; i++) {
  //       std::cout << vv[i] << ' ';
  //     }
  //     std::cout << '\n';
  //   }
  //   // std::cout << '\n';
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}