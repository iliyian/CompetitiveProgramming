// date: 2025-01-28 11:04:20
// tag: 比较玄乎的区间合并和纯暴力，模拟，考虑单点修改不会导致区间长度发生过大的变化，也就是答案区间基本是连续的，然后就可以开始模拟了
// 关键是发现单点修改量对结果区间的影响比较小

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::set<std::pair<int, int>> s;
  s.insert({m, m});
  for (int i = 1; i <= q; i++) {
    int x;
    std::cin >> x;
    std::set<std::pair<int, int>> t;
    for (auto [l, r] : s) {
      if (l <= x && x <= r) {
        if (l != r) {
          t.insert({l, r});
        }
        t.insert({1, 1});
        t.insert({n, n});
      } else if (x < l) {
        t.insert({l - 1, r});
      } else {
        t.insert({l, r + 1});
      }
    }
    s = t;
    for (auto [l, r] : t) {
      auto p = s.upper_bound({l, r});
      assert(l <= r && l >= 1 && r <= n);
      if (p == s.end()) continue;
      if (s.find({l, r}) == s.end()) continue;
      // std::cerr << l << ' ' << r << ' ' << p->first << ' ' << p->second << '\n';
      if (p->first == l) {
        s.erase(s.find({l, r}));
      } else if (p->second <= r) {
        s.erase(p);
      } else if (p->first <= r + 1) {
        auto t = std::pair{l, p->second};
        // assert(p != s.end());
        s.erase(p);
        s.erase(s.find({l, r}));
        // assert(s.find({l, r}) != s.end());
        s.insert(t);
      }
    }
    int ans = 0;
    int pr = -1;
    for (auto [l, r] : s) {
      // std::cerr << l << ' ' << r << '\n';
      ans += r - l + (pr != l);
      pr = r;
    }
    // std::cerr << s.size() << '\n';
    // std::cerr << '\n';
    std::cout << std::min(ans, n) << " ";
  }
  std::cout << '\n';
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