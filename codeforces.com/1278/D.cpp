// date: 2024-12-13 22:47:00
// tag: std::set往往可以用于处理一系列不计数而涉及相互关系的二维偏序问题，
// 一维存值一维存idx即可，如果要计数还这样做没准得上pb_ds

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  std::sort(a.begin() + 1, a.end());
  std::set<std::pair<int, int>> s;
  int cnt = 0;
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  std::iota(pa.begin(), pa.end(), 0);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  // for (int i = 1; i <= n; i++) {
  //   std::cout << a[i].first << ' ' << a[i].second << '\n';
  // }
  // return;
  for (int i = 1; i <= n; i++) {
    auto now = std::pair{a[i].first, INT_MAX};
    auto p = s.upper_bound(now);
    while (p != s.end()) {
      if (p->first > a[i].second) break;
      // std::cout << p->first << ' ' << p->second << '\n';
      // std::cout << i << ' ' << p->second << '\n';
      merge(i, p->second);
      now = {p->first, INT_MAX};
      p = s.upper_bound(now);
      cnt++;
      if (cnt > n - 1) {
        std::cout << "NO\n";
        return;
      }
    }
    s.insert({a[i].second, i});
  }
  if (cnt != n - 1) {
    std::cout << "NO\n";
    return;
  }
  bool f = false;
  for (int i = 1; i <= n; i++) {
    if (find(find, i) == i) {
      if (f) {
        std::cout << "NO\n";
        return;
      }
      f = true;
    }
  }
  std::cout << "YES\n";
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