// date: 2025-02-15 15:54:06
// tag: 每个点只有一个入边和出边的基环树森林

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  std::iota(pa.begin() + 1, pa.end(), 1);
  for (int i = 1; i <= n; i++) {
    int p;
    std::cin >> p;
    merge(i, p);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == find(find, i)) {
      ans += (siz[i] - 1) / 2;
    }
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