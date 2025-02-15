// date: 2025-01-25 14:51:49
// tag: 疑似还是得卡常的，贪心的位运算，连通性

#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;

int pa[64][N + 1], siz[64][N + 1];
// std::vector<std::pair<int, int>> g;

void solve() {
  int n, m, q, V;
  std::cin >> n >> m >> q >> V;
  // std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  std::vector<std::array<int, 3>> edges;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    edges.push_back({x, y, w});
  }
  // std::vector<std::vector<int>> id(61, std::vector<int>(n + 1));
  // std::vector<std::vector<std::vector<int>>> G(61, std::vector<std::vector<int>>(n + 1));
  // std::vector<std::vector<int>> pa(64, std::vector<int>(n + 1)), siz(64, std::vector<int>(n + 1, 1));
  for (int i = 63; i >= 0; i--) {
    for (int j = 1; j <= n; j++) {
      pa[i][j] = j;
      siz[i][j] = 1;
    }
  }
  auto find = [&](this auto &&self, int d, int x) -> int {return x == pa[d][x] ? x : pa[d][x] = self(d, pa[d][x]);};
  auto merge = [&](int d, int x, int y) {
    x = find(d, x), y = find(d, y);
    if (x == y) return;
    if (siz[d][x] > siz[d][y]) std::swap(x, y);
    pa[d][x] = y;
    siz[d][y] += siz[d][x];
  };
  for (auto &[x, y, w] : edges) {
    if ((V & w) >= V) {
      merge(63, x, y);
      // G[60][x].push_back(y);
      // G[60][y].push_back(x);
    }
    for (int i = 62; i >= 0; i--) {
      if (V >> i & 1 ^ 1 && w >> i & 1) {
        merge(i, x, y);
      } else if (V >> i & 1 && w >> i & 1 ^ 1) {
        break;
      }
    }
  }
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    bool f = false;
    for (int i = 63; i >= 0; i--) {
      // if (id[i][x] == id[i][y]) {
      if (find(i, x) == find(i, y)) {
        f = true;
        break;
      }
    }
    std::cout << (f ? "Yes" : "No") << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}