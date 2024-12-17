// 本质要求是覆盖两个点的集合不能完全一样
// 因此前缀异或和一下，看有多少个不同的点即可，异或哈希

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::array<int, 2>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][0] >> a[i][1];
  }
  std::sort(a.begin() + 1, a.end());
  auto in = [&](int x, int i) -> bool {
    return x >= a[i][0] && x <= a[i][1];
  };
  std::set<int> s;
  for (int i = 0; i <= 305; i++) {
    bool g = true;
    for (auto j : s) {
      bool f = false;
      for (int k = 1; k <= n; k++) {
        if (in(j, k) ^ in(i, k)) {
          f = true;
          break;
        }
      }
      if (!f) {
        g = false;
        break;
      }
    }
    if (g) {
      s.insert(i);
    }
  }
  std::cout << s.size() << '\n';
  // for (auto i : s) {
  //   std::cout << i << ' ';
  // }
  // std::cout << '\n';
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