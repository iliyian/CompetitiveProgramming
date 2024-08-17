// date: 2024-08-09 14:00:24
// tag: 暴力转图论转mst性质

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  std::vector<std::array<int, 3>> edges;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
      edges.push_back({a[i][j], i, j});
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i][i]) {
      std::cout << "NOT MAGIC\n";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (a[i][j] != a[j][i]) {
        std::cout << "NOT MAGIC\n";
        return 0;
      }
    }
  }

  std::vector<int> pa(n * n + 1), siz(n * n + 1, 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[y] < siz[x]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  std::iota(pa.begin(), pa.end(), 0);
  std::sort(edges.begin(), edges.end());
  for (int l = 0, r = 0; l < edges.size(); l = r) {
    while (r < edges.size() && edges[r][0] == edges[l][0]) {
      r++;
    }
    for (int i = l; i < r; i++) {
      auto [_, x, y] = edges[i];
      if (x != y && find(find, x) == find(find, y)) {
        std::cout << "NOT MAGIC\n";
        return 0;
      }
    }
    for (int i = l; i < r; i++) {
      auto [_, x, y] = edges[i];
      merge(x, y);
    }
  }
  std::cout << "MAGIC\n";

  return 0;
}