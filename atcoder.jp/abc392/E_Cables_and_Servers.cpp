// date: 2025-02-16 13:57:33
// tag: find(find, x) 是会随着操作改变的！！！不能在没有全部merge好之前就按照find(find,x)来更新某些只属于最后的pa的值！！！
// 还有其他操作也是类似，，不能边更新边存储，需要基于最终值的一些值，因为当前值非最终值

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  auto find = [&](auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  std::iota(pa.begin() + 1, pa.end(), 1);
  std::vector<std::vector<std::array<int, 3>>> edges(n + 1);
  std::vector<std::array<int, 3>> e;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    if (find(find, x) == find(find, y)) {
      e.push_back({x, y, i});
    } else {
      merge(x, y); 
    }
  }
  for (auto [x, y, id] : e) {
    edges[find(find, x)].push_back({x, y, id});
  }
  std::vector<std::array<int, 3>> cur;
  std::vector<int> vec;
  int s = 0;
  for (int i = 1; i <= n; i++) {
    if (find(find, i) == i) {
      vec.push_back(i);
    }
  }
  std::vector<std::array<int, 3>> ans;
  std::sort(vec.begin(), vec.end(), [&](const int &x, const int &y) {
    return edges[x].size() > edges[y].size();
  });
  for (int i = 0; i < vec.size() - 1; i++) {
    for (auto &x : edges[vec[i]]) {
      cur.push_back(x);
    }
    // assert(!cur.empty());
    auto [x, y, id] = cur.back(); cur.pop_back();
    ans.push_back({id, x, vec[i + 1]});
  }
  std::cout << ans.size() << '\n';
  for (auto [x, y, z] : ans) {
    std::cout << x << ' ' << y << ' ' << z << '\n';
  }
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