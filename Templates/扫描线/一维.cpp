// date: 2024-07-25 11:01:44
// tag: 扫描线

#include <bits/stdc++.h>
#include <iterator>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::array<int, 3>> seg;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int l, r;
    std::cin >> l >> r >> a[i];
    seg.push_back({l, 0, i});
    seg.push_back({r, 1, i});
  }
  std::sort(seg.begin(), seg.end());
  std::set<std::pair<int, int>> s;
  std::vector<std::array<int, 3>> edges;
  for (auto [pos, t, i] : seg) {
    if (t == 0) {
      auto it = s.insert({a[i], i}).first;
      auto l = std::prev(it);
      if (it != s.begin()) {
        edges.push_back({it->first - l->first, it->second, l->second});
      }
      auto r = std::next(it);
      if (r != s.end()) {
        edges.push_back({r->first - it->first, r->second, it->second});
      }
    } else {
      auto it = s.erase(s.find({a[i], i})); // for iterator
      if (it != s.end() && it != s.begin()) {
        auto l = std::prev(it);
        edges.push_back({it->first - l->first, it->second, l->second});
      }
    }
  }
  std::sort(edges.begin(), edges.end());
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) -> bool {
    x = find(find, x), y = find(find, y);
    if (x == y) {
      return false;
    }
    if (siz[x] > siz[y]) {
      std::swap(x, y);
    }
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  int ans = 0, cnt = 0;
  for (auto [w, x, y] : edges) {
    if (merge(x, y)) {
      ans += w;
      if (++cnt == n - 1) {
        break;
      }
    }
  }
  if (cnt != n - 1) {
    ans = -1;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}