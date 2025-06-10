// date: 2025-03-25 19:56:58
// tag: 并查集维护图连通性，数论，贪心，O(n^2)还是很轻松的，并且确实是最朴素的暴力做法了

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::pair<int, int>> ans;
  std::vector<int> pa(n + 1), siz(n + 1, 1);
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
  for (int i = n - 1; i >= 1; i--) {
    std::vector<std::array<int, 2>> b(n + 1, {0, 0});
    for (int j = 1; j <= n; j++) {
      auto x = a[j] % i;
      if (!b[x][0]) {
        b[x] = {find(find, j), j};
      } else if (merge(b[x][0], j)) {
        ans.push_back({b[x][1], j});
        break;
      }
    }
  }
  std::cout << "YES\n";
  for (auto [x, y] : ans | std::views::reverse) {
    std::cout << x << ' ' << y << '\n';
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