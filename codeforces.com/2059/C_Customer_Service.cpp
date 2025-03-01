// date: 2025-02-26 21:54:57
// tag: 什么基于某些观察的一眼贪心小垃圾
// 真就tmd考验注意力是吧

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
  std::multiset<int> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
    bool f = false;
    for (int j = n; j >= 1; j--) {
      if (a[i][j] != 1) {
        s.insert(n - j);
        f = true;
        break;
      }
    }
    if (!f) s.insert(n);
  }
  int mex = 1;
  // for (auto i : s) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  while (1) {
    auto p = s.lower_bound(mex);
    if (p != s.end()) {
      mex++;
      s.erase(p);
    } else break;
  }
  std::cout << std::min(mex, n) << '\n';
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