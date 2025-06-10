// date: 2025-05-19 15:07:47
// tag: 主要还是考察了图的dfs生成树只有返祖边这一性质，和生成树

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 2>> e(m + 1);
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    e[i] = {x, y};
    g[x].push_back({y, i});
    g[y].push_back({x, i});
  }
  std::vector<int> pa(n + 1), siz(n + 1, 1), is(m + 1);
  std::iota(pa.begin(), pa.end(), 0);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    siz[y] += siz[x];
    pa[x] = y;
    return true;
  };
  for (int i = 1; i <= m; i++) {
    auto [x, y] = e[i];
    if (merge(x, y)) {
      is[i] = 1;
    }
  }
  std::vector<std::vector<int>> _pa(21, std::vector<int>(n + 1));
  std::vector<int> dfn(n + 1), rnk(n + 1), dep(n + 1), _siz(n + 1);
  int tot = 0;
  // for (int i = 1; i <= m; i++) {
  //   std::cerr << is[i] << " \n"[i == m];
  // }
  auto dfs = [&](auto self, int u, int p) -> void {
    dfn[u] = ++tot;
    // if (tot >= n) {
      // std::cerr << u << ' ' << p << ' ' << n << '\n';
    // }
    rnk[tot] = u;
    // std::cerr << tot << '\n';
    _pa[0][u] = p;
    dep[u] = dep[p] + 1;
    _siz[u] = 1;
    for (int i = 1; i <= 20; i++) {
      _pa[i][u] = _pa[i - 1][_pa[i - 1][u]];
    }
    for (auto [v, id] : g[u]) {
      if (v != p && is[id]) {
        self(self, v, u);
        _siz[u] += _siz[v];
      }
    }
  };
  dfs(dfs, 1, 0);
  std::vector<int> d(n + 2);
  for (int i = 1; i <= m; i++) {
    if (!is[i]) {
      auto [x, y] = e[i];
      if (dep[x] > dep[y]) std::swap(x, y);
      int dif = dep[y] - dep[x];
      int w = y;
      for (int i = 0; i < 20; i++) {
        if ((dif - 1) >> i & 1) {
          w = _pa[i][w];
        }
      }
      if (_pa[0][w] == x) {
        d[dfn[y]]++, d[dfn[y] + _siz[y]]--;
        d[1]++;
        d[dfn[w]]--, d[dfn[w] + _siz[w]]++;
      } else {
        d[dfn[y]]++, d[dfn[y] + _siz[y]]--;
        d[dfn[x]]++, d[dfn[x] + _siz[x]]--;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    d[i] += d[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    std::cout << (d[dfn[i]] == m - n + 1);
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