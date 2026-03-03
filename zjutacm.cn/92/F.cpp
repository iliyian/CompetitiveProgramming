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
 * @File    : F.cpp
 * @Time    : 2025-12-21 12:38:54
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    a[i] = std::minmax({x, y});
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> pa(n + 1);
  for (int i = 1; i <= n; i++) {
    pa[i] = i;
  }
  auto fin = [&](auto self, int x) -> int {return x == pa[x] ? x : self(self, pa[x]);};
  auto find = [&](int x) -> int {return fin(fin, x);};
  std::vector<int> ce(n + 1), siz(n + 1, 1);
  std::stack<std::pair<int, int>> undo_sz, undo_pa, undo_ce;
  std::stack<int> dif;
  int now = 0;
  auto merge = [&](int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
      ce[x]++;
      undo_pa.push({-1, x});
      if (ce[x] <= siz[x]) {
        dif.push(1);
        now++;
        undo_sz.push({1, 1});
        undo_ce.push({1, 1});
      } else {
        dif.push(0);
        undo_sz.push({-1, -1});
        undo_ce.push({-1, -1});
      }
    } else {
      if (siz[x] > siz[y]) {
        std::swap(x, y);
      }
      int d = -std::min(ce[x], siz[x]) - std::min(ce[y], siz[y]);
      undo_pa.push({x, pa[x]});
      pa[x] = y;
      undo_sz.push({y, siz[y]});
      siz[y] += siz[x];
      undo_ce.push({y, ce[y]});
      ce[y] += ce[x] + 1;
      d += std::min(ce[y], siz[y]);
      dif.push(d);
      now += d;
    }
  };
  auto undo = [&]() {
    auto p = undo_pa.top(); undo_pa.pop();
    auto q = undo_sz.top(); undo_sz.pop();
    auto r = undo_ce.top(); undo_ce.pop();
    auto d = dif.top(); dif.pop();
    if (p.first == -1) {
      ce[p.second]--;
    } else {
      pa[p.first] = p.second;
      siz[q.first] = q.second;
      ce[q.first] = r.second;
    }
    now -= d;
  };
  std::vector<int> ans(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    merge(a[u].first, a[u].second);
    ans[u] = now;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
    undo();
  };
  dfs(dfs, 1, 0);
  for (int i = 2; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
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
