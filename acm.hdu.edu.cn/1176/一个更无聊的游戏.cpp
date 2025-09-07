// date: 2025-08-02 11:30:38
// tag: kruskal重构树模板+树上倍增

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n * 2), b(n * 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> pa(n * 2);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    pa[x] = y;
  };
  std::vector<int> p(n + 1);
  std::iota(p.begin(), p.end(), 0);
  std::iota(pa.begin(), pa.end(), 0);
  // std::ranges::iota(p, 0);
  // std::ranges::iota(pa, 0);
  std::sort(p.begin() + 1, p.end(), [&](auto x, auto y) {
    return a[x] < a[y];
  });
  int tot = n;
  std::vector<std::vector<int>> gg(n * 2);
  for (int i = 1; i <= n; i++) {
    int u = p[i];
    for (int v : g[u]) {
      int uu = find(find, u), vv = find(find, v);
      if (a[vv] > a[uu]) continue;
      if (uu != vv) {
        merge(vv, ++tot);
        merge(uu, tot);
        // a[tot] = std::max(a[vv], a[uu]);
        // 假设存在一条 1-2-3 的边
        // a值分别为 5 2 4
        // 如果2先合并了1，就会导致3无法合并2，因为2的2被1的5给遮住了
        // 不确定把g[u]也排序一下是否可以改善，但真不如按照原初的定义，只由大的那个发起连接......
        a[tot] = a[u];
        b[tot] = b[uu] + b[vv];
        gg[tot].push_back(uu);
        gg[tot].push_back(vv);
      }
    }
  }
  // for (int i = 1; i < n * 2; i++) {
  //   std::cout << i << ' ' << a[i] << ' ' << b[i] << '\n';
  //   for (int v : gg[i]) {
  //     std::cout << i << ' ' << v << '\n';
  //   }
  //   std::cout << '\n';
  // }
  std::vector<std::vector<int>> up(21, std::vector<int>(n * 2)), mx(21, std::vector<int>(n * 2));
  auto dfs = [&](auto self, int u, int p) -> void {
    up[0][u] = p;
    mx[0][u] = a[p] - b[u];
    for (int i = 1; i <= 20; i++) {
      up[i][u] = up[i - 1][up[i - 1][u]];
      mx[i][u] = std::max(mx[i - 1][u], mx[i - 1][up[i - 1][u]]);
    }
    for (int v : gg[u]) {
      self(self, v, u);
    }
  };
  dfs(dfs, n * 2 - 1, 0);
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    if (y < a[x]) {
      std::cout << y << '\n';
      continue;
    }
    // std::cerr << x << ' ';
    for (int i = 20; i >= 0; i--) {
      if (up[i][x] && mx[i][x] <= y) {
        x = up[i][x];
      }
    }
    // std::cerr << x << '\n';
    std::cout << y + b[x] << '\n';
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