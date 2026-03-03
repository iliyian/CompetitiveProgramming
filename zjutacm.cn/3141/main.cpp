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
 * @File    : main.cpp
 * @Time    : 2025-12-29 10:52:21
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

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
  std::vector<int> d1(n + 1), d2(n + 1), up(n + 1);
  int x = 0, y = 0;
  auto dfs1 = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        if (d1[v] + 1 > d1[u]) {
          d2[u] = d1[u];
          d1[u] = d1[v] + 1;
        } else if (d1[v] + 1 > d2[u]) {
          d2[u] = d1[v] + 1;
        }
      }
    }
  };
  auto dfs2 = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        up[v] = std::max(up[u] + 1, (d1[v] + 1 == d1[u] ? d2[u] : d1[u]) + 1);
        self(self, v, u);
      }
    }
  };
  dfs1(dfs1, 1, 0);
  dfs2(dfs2, 1, 0);
  int mn = LLONG_MAX / 3;
  for (int i = 1; i <= n; i++) {
    if (std::max(d1[i], up[i]) < mn) {
      mn = std::max(d1[i], up[i]);
      x = i, y = 0;
    } else if (std::max(d1[i], up[i]) == mn) {
      y = i;
    }
  }

  int ans = LLONG_MAX / 3;
  auto work = [&](int start, int len) {
    std::vector<int> cnt(n + 1), s(n + 1);
    int now = 0;
    auto add = [&](int x, int c, std::vector<int> &tr) -> void {if (x == 0) return; for (int i = x; i <= n; i += i & -i) tr[i] += c;};
    auto query = [&](int x, std::vector<int> &tr) -> int {int ans = 0; for (int i = x; i > 0; i -= i & -i) ans += tr[i]; return ans;};
    for (int i = 1; i <= (len + 1) / 2; i++) {
      now += i;
      add(1, 1, s);
      add(1, 1, cnt);
    }
    std::vector<int> height(n + 1, 1);
    auto _dfs = [&](auto self, int u, int p) -> void {
      for (int v : g[u]) {
        if (v != p) {
          self(self, v, u);
          height[u] = std::max(height[u], height[v] + 1);
        }
      }
    };
    _dfs(_dfs, start, 0);
    auto dfs2 = [&](auto self, int u, int p) -> void {
      if (height[u] == 1) {
        ans = std::min(ans, now);
        return;
      }
      int val = 0;
      for (int v : g[u]) {
        if (height[v] == height[u] - 1) {
          val++;
        }
      }
      if (u == start && len % 2 == 1) {
        val--;
      }
      now += query(val, s) + val + (query(n, cnt) - query(val, cnt)) * val;
      // std::cerr << query(val, s) << ' ' << val << ' ' << (dep[u] - 1 - query(val, cnt)) * val << '\n';
      add(val, 1, cnt);
      add(val, val, s);
      for (int v : g[u]) {
        if (height[v] == height[u] - 1) {
          self(self, v, u);
        }
      }
      add(val, -val, s);
      add(val, -1, cnt);
      now -= query(val, s) + val + (query(n, cnt) - query(val, cnt)) * val;
    };
    dfs2(dfs2, start, 0);
  };
  // std::cerr << x << ' ' << y << ' ' << d1[x] << ' ' << up[x] << '\n';
  int len = (y ? std::max(d1[x], up[x]) * 2 : std::max(d1[x], up[x]) * 2 + 1);
  // std::cerr << len << ' ' << y << '\n';
  work(x, len);
  if (y) {
    work(y, len);
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
