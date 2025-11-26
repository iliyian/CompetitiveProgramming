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
 * @File   : G.cpp
 * @Time   : 2025-10-15 19:30:03
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
  }
  std::ranges::sort(c);
  auto check = [&](int mid) -> bool {
    std::vector<int> p(n);
    std::ranges::iota(p, 0);
    std::vector<std::pair<int, int>> v;
    int L = LLONG_MIN, R = LLONG_MAX;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        if (b[i] >= mid) {
          v.push_back({L, R});
        } else {
          v.push_back({L, L});
        }
      } else if (a[i] > 0) {
        int l = std::ceil(1.0l * (mid - b[i]) / a[i]);
        v.push_back({l, R});
      } else {
        int r = std::floor(1.0l * (mid - b[i]) / a[i]);
        v.push_back({L, r});
      }
    }
    std::ranges::sort(p, [&](auto x, auto y) {
      return v[x] < v[y];
    });
    int ans = 0, pt = 0;
    for (int i = 0; i < n; i++) {
      auto &[l, r] = v[p[i]];
      while (pt < n && c[pt] < l) {
        pt++;
      }
      if (pt == n) break;
      if (c[pt] <= r) {
        pt++;
        ans++;
      }
      if (ans >= (n + 1) / 2) {
        return true;
      }
    }
    return false;
    // return ans >= (n + 1) / 2;
  };
  int l = (int)-3e18, r = (int)3e18, ans = LLONG_MAX;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
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
