#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m1, m2;
  std::cin >> n >> m1 >> m2;
  std::vector<int> pa1(n + 1), siz(n + 1, 1), pa2(n + 1);
  std::iota(pa1.begin(), pa1.end(), 0);
  std::iota(pa2.begin(), pa2.end(), 0);
  auto find = [](auto self, int x, std::vector<int> &pa) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x], pa);};
  auto merge = [&](int x, int y, std::vector<int> &pa) {
    x = find(find, x, pa), y = find(find, y, pa);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  std::vector<std::set<int>> g(n + 1);
  for (int i = 1; i <= m1; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].insert(y);
    g[y].insert(x);
  }
  for (int i = 1; i <= m2; i++) {
    int x, y;
    std::cin >> x >> y;
    merge(x, y, pa2);
  }
  std::vector<std::vector<int>> h(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (auto j : g[i]) {
      // if (find(find, i, pa2) != find(find, j, pa2)) {
      //   g[i].erase(j);
      // }
      if (find(find, i, pa2) == find(find, j, pa2)) {
        h[i].push_back(j);
      } else {
        ans++;
      }
    }
  }
  ans /= 2;
  // std::cout << ans << ' ';
  for (int i = 1; i <= n; i++) {
    for (auto j : h[i]) {
      merge(i, j, pa1);
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += find(find, i, pa1) == i;
  }
  for (int i = 1; i <= n; i++) {
    ans -= find(find, i, pa2) == i;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}