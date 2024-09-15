// date: 2024-09-12 11:26:46
// tag: 线性基，贪心

#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("main.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }
  std::sort(a.begin(), a.end());
  std::vector<int> d(63);
  auto insert = [&](int x) {
    for (int i = 62; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i]) {
          x ^= d[i];
        } else {
          d[i] = x;
          return;
        }
      }
    }
  };
  auto query = [&](int x) {
    for (int i = 62; i >= 0; i--) {
      if (x >> i & 1) {
        if (d[i]) {
          x ^= d[i];
        } else {
          return false;
        }
      }
    }
    return true;
  };
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (!query(a[i])) {
      insert(a[i]);
    } else {
      ans += a[i];
    }
  }
  std::cout << ans << '\n';
  return 0;
}