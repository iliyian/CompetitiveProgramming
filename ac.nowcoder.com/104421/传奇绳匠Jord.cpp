#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    merge(x, y);
  }
  int q;
  std::cin >> q;
  int x = 0;
  bool f = true;
  for (int i = 1; i <= q; i++) {
    int y;
    std::cin >> y;
    y = find(find, y);
    if (x && x != y) {
      f = false;
    } else {
      x = y;
    }
  }
  std::cout << (f ? "YES" : "NO") << '\n';
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