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
 * @File    : P_14753_森.cpp
 * @Time    : 2025-12-19 18:32:37
 * @Comment : 怎么说呢，思路很清晰，不过是多套了一层，但为什么就是不会呢？
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::stack<int> s;
  std::vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      r[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    r[s.top()] = n + 1; s.pop();
  }
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] > a[i]) {
      l[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  std::vector<int> lcnt(n + 1), rcnt(n + 1), d(n + 1);
  auto add = [&](int x, int c) -> void {for (int i = x; i <= n; i += i & -i) d[i] += c;};
  auto query = [&](int x) -> int {int ans = 0; for (int i = x; i > 0; i -= i & -i) ans += d[i]; return ans;};
  std::vector<std::vector<std::pair<int, int>>> ask(n + 2);
  for (int i = 1; i <= n; i++) {
    ask[l[i]].push_back({i, a[i]});
  }
  for (int i = 1; i <= n; i++) {
    add(a[i], 1);
    for (auto [idx, v] : ask[i]) {
      lcnt[idx] = query(v - 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    ask[i].clear();
  }
  std::ranges::fill(d, 0);
  for (int i = n; i >= 1; i--) {
    ask[r[i]].push_back({i, a[i]});
  }
  for (int i = n; i >= 1; i--) {
    add(a[i], 1);
    for (auto [idx, v] : ask[i]) {
      rcnt[idx] = query(v - 1);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += lcnt[i] * rcnt[i] % mod * (i - l[i]) % mod * (r[i] - i) % mod;
    ans %= mod;
    // std::cerr << lcnt[i] << ' ' << rcnt[i] << ' ' << l[i] << ' ' << r[i] << '\n';
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
