// date: 2025-08-08 22:21:28
// tag: 
// 点分治卡了半天常终于卡过去了。把点分治里面的id(w)都提到外面来，然后只在必要时O(1)在离散化数组上查询。
// 虽然总体复杂度还是O(nlog^{2}n)，但是常数将近少了一半

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9 + 7;

// int _cur[(int)1e5 + 1], _old[(int)1e5 + 1];

void solve() {
  int n, m, w;
  std::cin >> n >> m >> w;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<std::array<int, 3>> e(m);
  std::vector<int> vec = {LLONG_MIN};
  auto id = [&](int x) {
    return std::ranges::lower_bound(vec, x) - vec.begin();
  };
  int ans = 0;
  std::vector<int> pa(n + 1), sz(n + 1, 1);
  std::iota(pa.begin(), pa.end(), 0);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) -> bool {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (sz[x] > sz[y]) std::swap(x, y);
    pa[x] = y;
    sz[y] += sz[x];
    return true;
  };
  for (int i = 0; i < m; i++) {
    auto &[w, x, y] = e[i];
    std::cin >> x >> y >> w;
    vec.push_back(w);
  }
  std::ranges::sort(e);
  std::ranges::sort(vec);
  int block = n;
  for (auto &[w, x, y] : e) {
    if (merge(x, y)) {
      w = id(w);
      g[x].push_back({y, w});
      g[y].push_back({x, w});
      block--;
    }
  }
  if (block > 2) {
    std::cout << 0 << '\n';
    return;
  }
  if (block == 2) {
    for (int i = 2; i <= n; i++) {
      if (find(find, i) != find(find, 1)) {
        std::cout << sz[pa[i]] * sz[pa[1]] % mod * w % mod << '\n';
        return;
      }
    }
    assert(false);
  }
  std::vector<int> siz(n + 1), maxx(n + 1), vis(n + 1);
  int tot = n;
  int rt = 0;
  maxx[0] = LLONG_MAX;
  auto getrt = [&](auto self, int u, int p) -> void {
    maxx[u] = 0;
    siz[u] = 1;
    for (auto [v, w] : g[u]) {
      if (v != p && !vis[v]) {
        self(self, v, u);
        siz[u] += siz[v];
        maxx[u] = std::max(maxx[u], siz[v]);
      }
    }
    maxx[u] = std::max(maxx[u], tot - siz[u]);
    if (maxx[u] < maxx[rt]) {
      rt = u;
    }
  };
  std::vector<int> tr1(m + 1), tr2(m + 1);
  auto add = [&](int x, int c, std::vector<int> &d) -> void {for (int i = x; i <= m; i += i & -i) d[i] += c, d[i] %= mod;};
  auto query = [&](int x, std::vector<int> &d) -> int {int ans = 0; for (int i = x; i > 0; i -= i & -i) ans += d[i], ans %= mod; return ans;};
  // int cur = 0, old = 0;
  std::vector<int> cur, old;
  cur.reserve(n + 1);
  old.reserve(n + 1);
  int sum = 0;
  auto dfs = [&](auto self, int u, int p, int mx) -> void {
    // _cur[++cur] = mx;
    cur.push_back(mx);
    int i = mx;
    ans += sum - query(i, tr1) + mod; // > w
    ans %= mod;
    ans += (vec[i] - 1) * (query(i, tr2) + 1) % mod; // <= w
    ans %= mod;
    for (auto &[v, w] : g[u]) {
      if (!vis[v] && v != p) {
        self(self, v, u, std::max(mx, w));
      }
    }
  };
  int _tot = 0, _mxd = 0;
  auto start = std::chrono::high_resolution_clock::now();
  auto work = [&](auto &&self, int u, int p, int d) -> void {
    vis[u] = 1;
    _tot++;
    _mxd = std::max(_mxd, d);
    sum = 0;
    for (auto &[v, w] : g[u]) {
      if (!vis[v] && v != p) {
        dfs(dfs, v, 0, w);
        while (!cur.empty()) {
          int u = cur.back(); cur.pop_back();
          old.push_back(u);
          // int u = _cur[cur--];
          // _old[++old] = u;
          add(u, vec[u] - 1, tr1);
          add(u, 1, tr2);
          sum = (sum + vec[u] - 1) % mod;
        }
      }
    }
    while (!old.empty()) {
      int u = old.back(); old.pop_back();
      add(u, (-vec[u] + 1 + mod) % mod, tr1);
      add(u, mod - 1, tr2);
    }
    for (auto &[v, w] : g[u]) {
      if (!vis[v] && v != p) {
        tot = siz[v];
        rt = 0;
        getrt(getrt, v, u);
        self(self, rt, u, d + 1);
      }
    }
  };
  getrt(getrt, 1, 0);
  work(work, rt, 0, 1);

  std::vector<std::vector<int>> up(18, std::vector<int>(n + 1)), mx(18, std::vector<int>(n + 1));
  std::vector<int> dep(n + 1);
  auto dfs2 = [&](auto &&self, int u, int p) -> void {
    for (auto &[v, w] : g[u]) {
      if (__builtin_expect(v != p, 1)) {
        up[0][v] = u;
        mx[0][v] = w;
        dep[v] = dep[u] + 1;
        for (int i = 1; i <= 17; i++) {
          up[i][v] = up[i - 1][up[i - 1][v]];
          mx[i][v] = std::max(mx[i - 1][v], mx[i - 1][up[i - 1][v]]);
        }
        self(self, v, u);
      }
    }
  };
  auto lca = [&](int x, int y) -> int {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 17; i >= 0; i--) {
      if (dep[up[i][x]] >= dep[y]) {
        x = up[i][x];
      }
    }
    if (x == y) return x;
    for (int i = 17; i >= 0; i--) {
      if (up[i][x] != up[i][y]) {
        x = up[i][x], y = up[i][y];
      }
    }
    return up[0][x];
  };
  auto get = [&](int x, int y) {
    int d = dep[x] - dep[y], ans = 0;
    for (int i = 17; i >= 0; i--) {
      if (d >> i & 1) {
        ans = std::max(ans, mx[i][x]);
        x = up[i][x];
      }
    }
    return ans;
  };
  auto calc = [&](int x, int y) {
    int l = lca(x, y);
    return std::max(get(x, l), get(y, l));
  };
  dep[1] = 1;
  dfs2(dfs2, 1, 0);
  for (auto &[w, x, y] : e) {
    ans += mod - (vec[calc(x, y)] - 1);
    ans %= mod;
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