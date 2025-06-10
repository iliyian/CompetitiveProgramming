// date: 2025-04-30 17:03:07
// tag: 想了好几个星期的妙妙题属于是。简直跟上次杭电那个哈希题有得一拼。都是先确定一个很少的上界，然后从式子的一侧构造，再反过来确认构造的是否正确。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string sn = std::to_string(n);
  int lenn = sn.size();
  std::vector<std::pair<int, int>> v;
  for (int b = 1; b <= 10000; b++) {
    for (int len = 1; len <= 7; len++) {
      if ((len + b) % lenn) continue;
      int a = (len + b) / lenn;
      if (a > 10000) continue;
      int ans = a * n - b;
      std::string sans;
      for (int i = 0; i < a * lenn - b; i++) {
        sans.push_back(sn[i % lenn]);
      }
      if (sans == std::to_string(ans)) {
        v.push_back({a, b});
      }
    }
  }
  std::cout << v.size() << '\n';
  for (auto [x, y] : v) {
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