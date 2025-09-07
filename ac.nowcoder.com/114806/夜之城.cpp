// date: 2025-08-02 16:05:54
// tag: 带权并查集，环与异或？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  bool f = true;
  std::vector<int> pa(n * 2), val(n * 2);
  std::ranges::iota(pa, 0);
  auto find = [&](auto self, int x) -> int {
    if (x == pa[x]) return x;
    int p = self(self, pa[x]);
    val[x] ^= val[pa[x]];
    return pa[x] = p;
  };
  while (q--) {
    int x, y, v;
    std::cin >> x >> y >> v;
    x--, y = y - 1 + n;
    if (!f) {
      std::cout << "NO\n";
      continue;
    }
    int px = find(find, x), py = find(find, y);
    if (px == py) {
      if (val[x] ^ val[y] ^ v) {
        f = false;
        std::cout << "NO\n";
      } else {
        std::cout << "YES\n";
      }
    } else {
      pa[px] = py;
      val[px] = val[x] ^ val[y] ^ v;
      std::cout << "YES\n";
    }
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