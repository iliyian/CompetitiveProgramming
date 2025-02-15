// date: 2025-01-30 16:09:40
// tag: 有些性质实际上有更简单更实用的等价表述
// 例如左侧所有值小于右侧所有值，也就是左侧最大值小于右侧最小值，在整体所有值构成排列的前提下，等价于左侧整体构成了一个排列，根本不需要他妈的傻逼的RMQ
// 大概是这样？
// 属于是排列的性质，排列的性质，然后小模拟，常见的动态维护当前不可行的点

#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> b;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  std::set<int> s;
  int lst = 0;
  for (int i = 1; i <= n; i++) {
    s.insert(a[i]);
    while (!s.empty() && *s.begin() == lst + 1) {
      lst++;
      s.erase(s.begin());
    }
    if (s.empty()) {
      b.push_back(i); // i和i+1是好的分割点
    }
  }
  assert(s.empty());
  auto add = [&](int i) {
    if (str[i] == 'L' && str[i + 1] == 'R') {
      auto p = std::lower_bound(b.begin(), b.end(), i);
      if (p == b.end() || *p != i) {
        s.insert(i); // bad
      }
    }
  };
  auto del = [&](int x) {
    auto p = s.find(x);
    if (p != s.end()) {
      s.erase(p);
    }
  };
  for (int i = 1; i <= n; i++) {
    add(i);
  }
  while (q--) {
    int x;
    std::cin >> x;
    if (str[x - 1] == 'L' && str[x] == 'R') {
      del(x - 1);
    }
    if (str[x] == 'L' && str[x + 1] == 'R') {
      del(x);
    }
    str[x] = (str[x] == 'L' ? 'R' : 'L');
    if (str[x - 1] == 'L' && str[x] == 'R') {
      add(x - 1);
    }
    if (str[x] == 'L' && str[x + 1] == 'R') {
      add(x);
    }
    std::cout << (s.empty() ? "YES" : "NO") << '\n';
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