// date: 2025-03-01 22:47:21
// tag: 所以说位运算基本就是按位从高到低贪心是吧，基于不同位的相对独立性？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) std::cin >> i;
  std::vector<int> d(n + 1);
  auto add = [&](int x, int c) -> void {
    x++;
    for (int i = x; i <= n; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) -> int {
    int ans = 0;
    x++;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  auto calc = [&]() -> int {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      add(a[i], 1);
      ans += i + 1 - query(a[i]);
    }
    for (int i = 0; i < n; i++) {
      add(a[i], -1);
    }
    return ans;
  };
  int ans = 0, len = std::__lg(n);
  for (int i = len - 1; i >= 0; i--) {
    int prv = calc();
    for (int j = 0; j < n; j++) {
      a[j] ^= 1 << i;
    }
    ans ^= 1 << i;
    int cur = calc();
    if (cur > prv) {
      ans ^= 1 << i;
      for (int j = 0; j < n; j++) {
        a[j] ^= 1 << i;
      }
    }
  }
  std::cout << (calc() + (ans ? 1 : 0)) << '\n';
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
