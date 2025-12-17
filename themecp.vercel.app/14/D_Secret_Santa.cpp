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
 * @File    : D_Secret_Santa.cpp
 * @Time    : 2025-12-04 10:27:44
 * @Comment : 从没写过这么屎的代码
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve(int _t) {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), in(n + 1), dep(n + 1), pa(n + 1), siz(n + 1, 1);
  std::ranges::iota(pa, 0);
  auto find = [&](this auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    in[a[i]]++;
    merge(i, a[i]);
  }
  std::vector<std::vector<int>> p(n + 1);
  for (int i = 1; i <= n; i++) {
    p[find(i)].push_back(i);
  }
  std::vector<int> ans(n + 1), ring(n + 1);
  std::vector<int> vis(n + 1);
  for (auto &v : p) {
    if (v.empty()) continue;
    std::queue<int> q;
    for (int i : v) {
      if (!in[i]) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (!--in[a[u]]) {
        q.push(a[u]);
      }
    }
    for (int i : v) {
      if (in[i]) {
        ring[i] = 1;
      }
    }
    for (int i : v) {
      if (!ring[i]) {
        in[a[i]]++;
      }
    }
    for (int i : v) {
      if (!in[i]) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front(); q.pop();
      assert(dep[a[u]] <= dep[u] + 1);
      dep[a[u]] = dep[u] + 1;
      if (!--in[a[u]] || ring[a[u]]) {
        if (!vis[a[u]]) {
          ans[u] = a[u];
          vis[a[u]] = 1;
        }
        if (!in[a[u]]) {
          q.push(a[u]);
        }
      }
    }
    int mx = v.front();
    for (int i : v) {
      if (in[i]) {
        if (dep[i] > dep[mx]) {
          mx = i;
        }
      }
    }
    int from = mx;
    while (a[mx] != from) {
      if (!vis[a[mx]]) {
        ans[mx] = a[mx];
        vis[a[mx]] = 1;
      }
      mx = a[mx];
    }
    if (dep[from] == 0) {
      ans[mx] = from;
    }
  }
  for (int i = 1; i <= n; i++) {
    vis[ans[i]] = 1;
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << ans[i] << ' ';
  // }
  // std::cerr << '\n';
  std::vector<int> sp, good;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (!ans[i]) {
      while (tot <= n && vis[tot]) tot++;
      ans[i] = tot;
      vis[tot] = 1;
      if (ans[i] == i) {
        sp.push_back(i);
      } else {
        good.push_back(i);
      }
    }
  }
  if (sp.size() == 1) {
    std::swap(ans[sp.front()], ans[good.front()]);
  } else 
    for (int i = 0; i < sp.size(); i++) {
      ans[sp[i]] = sp[(i + 1) % sp.size()];
    }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += ans[i] == a[i];
  }
  std::cout << cnt << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;
  // if (t == 2) {
    while (t--) {
      solve(0);
    }
    return 0;
  // }

  for (int _t = 1; _t <= t; _t++) {
    // solve(i);
    int n;
    std::cin >> n;
    if (_t == 56) {
      std::cout << n << '\n';
    }
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x;
      if (_t == 56) {
        std::cout << x << ' ';
      }
    }
  }

  return 0;
}
