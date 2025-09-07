#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> in(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    in[x]++, in[y]++;
  }
  int tot = 0, maxd = 0;
  std::vector<int> cnt(n + 1), dep(n + 1);
  auto add = [&](int x) {
    cnt[x]++;
    if (cnt[x] == 1) {
      tot++;
    }
  };
  auto del = [&](int x) {
    cnt[x]--;
    if (cnt[x] == 0) {
      tot--;
    }
  };
  int c = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    add(a[u]);
    dep[u] = tot;
    if (dep[u] > dep[c] && in[u] == 1) {
      c = u;
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
    del(a[u]);
  };
  int rt = 1;
  while (in[rt] != 1) rt++;
  // std::cerr << rt << '\n';
  dfs(dfs, rt, 0);
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << dep[i] << ' ';
  // }
  // std::cerr << '\n' << c << '\n';
  std::cerr << c << '\n';
  std::ranges::fill(dep, 0);
  int t = c;
  c = 0;
  dfs(dfs, t, 0);
  std::cerr << c << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << dep[i] << ' ';
  // }
  // std::cerr << '\n' << c << '\n';
  t = c;
  c = 0;
  std::ranges::fill(dep, 0);
  dfs(dfs, t, 0);
  std::cerr << c << '\n';
  std::cout << dep[c] << '\n';
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