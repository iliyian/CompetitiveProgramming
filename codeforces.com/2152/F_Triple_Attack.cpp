// 突然发现左开右闭区间和零索引也是很好的......
// 因为最后一个刚好可以作为哨兵！

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
 * @File   : F_Triple_Attack.cpp
 * @Time   : 2025-10-09 19:51:57
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, z;
  std::cin >> n >> z;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  const int logn = std::__lg(n);
  std::vector<std::vector<int>> f(logn + 1, std::vector<int>(n + 1));
  std::vector<int> dep(n + 1);
  f[0][n] = n;
  int j = 1;
  for (int i = 0; i < n; i++) {
    while (j < n && a[j] - a[i] <= z) {
      j++;
    }
    f[0][i] = j;
  }
  for (int i = n - 1; i >= 0; i--) {
    dep[i] = 1 + dep[f[0][i]];
  }
  for (int j = 0; j < logn; j++) {
    for (int i = 0; i <= n; i++) {
      f[j + 1][i] = f[j][f[j][i]];
    }
  }
  auto lca = [&](int x, int y) {
    if (dep[x] < dep[y]) {
      std::swap(x, y);
    }
    int ans = 0;
    for (int i = logn; i >= 0; i--) {
      if (dep[f[i][x]] >= dep[y]) {
        x = f[i][x];
      }
    }
    if (x == y) {
      return x;
    }
    for (int i = logn; i >= 0; i--) {
      if (f[i][x] != f[i][y]) {
        x = f[i][x], y = f[i][y];
        ans += 2ll << i;
      }
    }
    return f[0][x];
  };
  std::vector<std::vector<int>> nxt(logn + 1, std::vector<int>(n + 1));
  std::vector<std::vector<int>> stp(logn + 1, std::vector<int>(n + 1));
  nxt[0][n] = n;
  for (int i = 0; i < n; i++) {
    auto z = lca(i, i + 1);
    auto s = dep[i] + dep[i + 1] - 2 * dep[z];
    nxt[0][i] = z;
    stp[0][i] = s;
  }
  for (int j = 0; j < logn; j++) {
    for (int i = 0; i <= n; i++) {
      nxt[j + 1][i] = nxt[j][nxt[j][i]];
      stp[j + 1][i] = stp[j][i] + stp[j][nxt[j][i]];
    }
  }
  auto calc = [&](int l, int r) {
    int ans = 0;
    if (l >= r) return 0ll;
    for (int i = logn; i >= 0; i--) {
      if (f[i][l] < r) {
        l = f[i][l];
        ans += 1ll << i;
      }
    }
    return ans + 1;
  };
  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    l--;
    if (r - l <= 2) {
      std::cout << r - l << '\n';
      continue;
    }
    int ans = 0;
    for (int j = logn; j >= 0; j--) {
      if (nxt[j][l] < r) {
        ans += stp[j][l];
        l = nxt[j][l];
      }
    }
    for (auto z : {0, 1}) {
      ans += calc(l + z, r);
    }
    std::cout << ans << '\n';
  }
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
