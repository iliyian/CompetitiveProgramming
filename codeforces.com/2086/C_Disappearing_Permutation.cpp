#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  // std::vector<std::vector<int>> g(n + 1);
  std::vector<int> a(n + 1), d(n + 1);
  std::vector<int> siz(n + 1, 1), pa(n + 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) -> bool {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    merge(i, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> d[i];
  }
  std::vector<int> vis(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    d[i] = find(find, d[i]);
    if (!vis[d[i]]) {
      vis[d[i]] = 1;
      ans += siz[d[i]];
    }
    std::cout << ans << ' ';
  }
  std::cout << '\n';
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