// date: 2025-05-13 18:20:41
// tag: 还算比较有趣的数论题吧，不禁让我想到，奇偶在整数域对加减都构成阿贝尔群，且只有很少的几种运算结果，这就是突破口了，顺便平方的奇偶不变也很常用，顺便这题似乎还能从向量的角度出发？向量有奇偶吗

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, sx, sy;
  std::cin >> n >> sx >> sy;
  std::array<std::set<int>, 2> s;
  std::vector<int> x(n + 1), y(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i];
    int sum = std::abs(x[i] - sx) + std::abs(y[i] - sy);
    s[sum % 2].insert(i);
  }
  if (s[1].size() <= s[0].size()) {
    std::cout << "First" << std::endl;
    while (1) {
      if (!s[1].empty()) {
        std::cout << *s[1].begin() << std::endl;
        s[1].erase(s[1].begin());
      } else if (!s[0].empty()) {
        std::cout << *s[0].begin() << std::endl;
        s[0].erase(s[0].begin());
      } else {
        break;
      }
      if (s[0].empty() && s[1].empty()) break;
      int i;
      std::cin >> i;
      int sum = std::abs(x[i] - sx) + std::abs(y[i] - sy);
      s[sum % 2].erase(i);
    }
  } else {
    std::cout << "Second" << std::endl;
    while (1) {
      if (s[0].empty() && s[1].empty()) break;
      int i;
      std::cin >> i;
      int sum = std::abs(x[i] - sx) + std::abs(y[i] - sy);
      s[sum % 2].erase(i);
      if (!s[0].empty()) {
        std::cout << *s[0].begin() << std::endl;
        s[0].erase(s[0].begin());
      } else if (!s[1].empty()) {
        std::cout << *s[1].begin() << std::endl;
        s[1].erase(s[1].begin());
      } else {
        break;
      }
    }
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