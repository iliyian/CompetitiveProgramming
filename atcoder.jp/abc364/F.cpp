// date: 2024-07-28 09:23:39
// tag: 最小生成树，dsu维护

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, q;
  std::cin >> n >> q;
  std::vector<std::array<int, 3>> a(q + 1);
  for (int i = 1; i <= q; i++) {
    std::cin >> a[i][1] >> a[i][2] >> a[i][0];
  }
  std::sort(a.begin() + 1, a.end());
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) {
      return;
    }
    if (x > y) {
      std::swap(x, y);
    }
    pa[x] = y;
    siz[y] += siz[x];
  };
  int ans = 0;
  for (auto [c, l, r] : a) {
    for (int i = l; i <= r; i++) {
      i = find(find, i);
      if (i + 1 <= r) {
        merge(i, i + 1);
      }
      ans += c;
    }
  }
  std::cout << (siz[find(find, 1)] == n ? ans : -1) << '\n';

  return 0;
}