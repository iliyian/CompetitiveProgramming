// date: 2024-12-19 22:13:59
// tag: 双堆维护中位数，值-索引的一类题

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] -= i;
  }
  // for (int i = 1; i <= n; i++) {
  //   a[i] += a[i - 1];
  // }
  std::multiset<int> s1, s2;
  s1.insert(INT_MIN);
  s2.insert(INT_MAX);
  int sum2 = 0, sum1 = 0;
  auto update = [&]() {
    if (s1.size() > s2.size() + 1) {
      auto x = *s1.rbegin();
      s1.erase(s1.find(x));
      s2.insert(x);
      sum1 -= x, sum2 += x;
    }
    if (s1.size() < s2.size()) {
      auto x = *s2.begin();
      s2.erase(s2.begin());
      s1.insert(x);
      sum1 += x, sum2 -= x;
    }
  };
  auto add = [&](int x) {
    if (*s1.rbegin() >= x) {
      s1.insert(x);
      sum1 += x;
    } else {
      s2.insert(x);
      sum2 += x;
    }
    update();
  };
  auto erase = [&](int x) {
    if (*s1.rbegin() >= x) {
      s1.erase(s1.find(x));
      sum1 -= x;
    } else {
      s2.erase(s2.find(x));
      sum2 -= x;
    }
    update();
  };
  int ans = 1;
  auto check = [&]() {
    int mid = *s1.rbegin();
    int res = mid * (s1.size() - 1) - sum1 + sum2 - mid * (s2.size() - 1);
    if (res <= k) {
      return true;
    }
    return false;
  };
  for (int l = 1, r = 0; l <= n; erase(a[l++])) {
    while (r + 1 <= n) {
      add(a[r + 1]);
      if (!check()) {
        erase(a[r + 1]);
        break;
      }
      r++;
    }
    ans = std::max(ans, r - l + 1);
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}