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
 * @File    : C.cpp
 * @Time    : 2025-11-01 12:12:54
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n), b(m);
  for (int &i : a) std::cin >> i;
  for (int &i : b) std::cin >> i;
  a.push_back(1e18);
  b.push_back(1e18);
  std::vector<int> pa(n + 1), pb(m + 1);
  std::ranges::iota(pa, 0);
  std::ranges::iota(pb, 0);
  std::ranges::sort(pa, [&](auto x, auto y) {
    return a[x] < a[y];
  });
  std::ranges::sort(pb, [&](auto x, auto y) {
    return b[x] < b[y];
  });
  std::priority_queue<std::array<int, 4>, std::vector<std::array<int, 4>>, std::greater<>> q;
  std::map<std::array<int, 3>, int> mp;
  std::map<std::array<int, 3>, std::array<int, 3>> pre;
  mp[{0, 0, 0}] = mp[{1, 0, 0}] = 0;
  q.push({0, 0, 0, 0});
  q.push({0, 1, 0, 0});
  while (!q.empty()) {
    auto [t, tp, u, v] = q.top(); q.pop();
    if (mp[{tp, u, v}] != t) continue;
    if (u == n && v == m) {
      std::vector<std::array<int, 3>> ans;
      std::cout << t << '\n';
      while (u || v) {
        auto pr = pre[{tp, u, v}];
        t -= k;
        if (u != pr[1]) {
          ans.push_back({t, tp ^ 1, pa[pr[1]] + 1});
        } else if (v != pr[2]) {
          ans.push_back({t, tp ^ 1, pb[pr[2]] + 1});
        } else {
        }
        tp = pr[0], u = pr[1], v = pr[2];
      }
      std::ranges::reverse(ans);
      for (auto [t, tp, v] : ans) {
        std::cout << t << ' ' << tp << ' ' << v << '\n';
      }
      return;
    }
    auto update = [&](int tp, int u, int v, int t) {
      if (!mp.contains({tp, u, v}) || mp[{tp, u, v}] > t) {
        mp[{tp, u, v}] = t;
        q.push({t, tp, u, v});
        return true;
      }
      return false;
    };
    if (tp == 0) {
      t = std::max(t, std::min(a[pa[u]], b[pb[v]] - k));
      if (a[pa[u]] > t && update(1, u, v, t + k)) {
        pre[{1, u, v}] = {tp, u, v};
      }
      if (a[pa[u]] < t + 2 * k && update(1, u + 1, v, std::max(a[pa[u]], t) + k)) {
        pre[{1, u + 1, v}] = {tp, u, v};
      }
    }
    if (tp == 1) {
      t = std::max(t, std::min(b[pb[v]], a[pa[u]] - k));
      if (b[pb[v]] > t && update(0, u, v, t + k)) {
        pre[{0, u, v}] = {tp, u, v};
      }
      if (b[pb[v]] < t + 2 * k && update(0, u, v + 1, std::max(b[pb[v]], t) + k)) {
        pre[{0, u, v + 1}] = {tp, u, v};
      }
    }
  }
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
