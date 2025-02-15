#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  std::set<int> s;
  auto find = [&](auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  std::iota(pa.begin() + 1, pa.end(), 1);
  // std::vector<std::vector<std::array<int, 3>>> edges(n + 1);
  std::vector<std::array<int, 3>> edges;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    edges.push_back({x, y, i});
    if (find(find, x) == find(find, y)) {
    } else {
      merge(x, y); 
    }
  }
  std::vector<std::vector<std::array<int, 3>>> vec;
  for (auto [x, y, id] : edges) {
    if (find(find, x) == find(find, y)) {
      vec[find(find, x)].push_back({x, y, id});      
    }
  }
  for (int i = 1; i )
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}