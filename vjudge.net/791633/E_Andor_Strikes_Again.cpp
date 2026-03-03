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
 * @File    : E_Andor_Strikes_Again.cpp
 * @Time    : 2026-02-23 14:13:59
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;

void solve() {
  int n;
  char c;
  std::cin >> n >> c;
  std::string s = "AO";
  if (c == 'O') {
    s = "OA";
  }
  std::queue<int> q;
  std::vector<int> sum(N + 1), a(N + 1, -1);
  std::vector<std::vector<int>> g(N + 1);
  int rt, tot = 0;
  std::cin >> rt;
  sum[++tot] = rt;
  q.push(tot);
  while (!q.empty()) {
    std::string v;
    std::cin >> v;
    int u = q.front();
    if (!--sum[u]) q.pop();
    ++tot;
    if (v == "T") {
      a[tot] = 1;
    } else if (v == "F") {
      a[tot] = 0;
    } else {
      int num = std::stoll(v);
      sum[tot] = num;
      q.push(tot);
    }
    g[u].push_back(tot);
  }
  auto dfs = [&](auto self, int u, int dep) -> int { // 改变的最小操作数
    if (g[u].empty()) return 1;
    char c = s[dep & 1];
    if (c == 'A') {
      a[u] = 1;
    } else {
      a[u] = 0;
    }
    int sumf = 0, mn = LLONG_MAX / 3, sumt = 0;
    for (int v : g[u]) {
      int vall = self(self, v, dep + 1);
      mn = std::min(mn, vall);
      if (a[v] == 1) {
        sumt += vall;
      } else {
        sumf += vall;
      }
    }
    for (int v : g[u]) {
      if (c == 'A') {
        a[u] &= a[v];
      } else {
        a[u] |= a[v];
      }
    }
    if (c == 'A') {
      if (a[u]) {
        return mn;
      } else {
        return sumf;
      }
    } else {
      if (a[u]) {
        return sumt;
      } else {
        return mn;
      }
    }
  };
  std::cout << dfs(dfs, 1, 0) << '\n';
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
