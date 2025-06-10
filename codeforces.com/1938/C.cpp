// date: 2025-05-07 23:30:32
// tag: 开心，一遍过，果然还是得从题目最薄弱处下手，疑似位运算题目

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int mn = -1;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (mn == -1 || a[i] < a[mn]) {
      mn = i;
    }
  }
  int r = a[mn] - 1;
  if (a[mn] == 0) {
    for (int i = 1; i <= n; i++) {
      if (__builtin_popcountll(i - 1) != a[i]) {
        std::cout << -1 << '\n';
        return;
      }
    }
    std::cout << 0 << '\n';
    return;
  }
  
  int x = 1;
  for (int d = 0; d <= 60; d++, x <<= 1) {
    bool f = true;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      int di = i - mn;
      if (x + di < 0 || __builtin_popcountll(x + di) != a[i] - r) {
        f = false;
        break;
      }
      mx = std::max<int>(mx, 63 - __builtin_clzll(x + di));
    }
    if (f) {
      x -= mn - 1;
      for (int i = mx + 1; i <= mx + r; i++) {
        x |= 1ll << i;
      }
      std::cout << x << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int i = 1; i <= 100; i++) {
  //   std::cerr << i << ' ' << __builtin_popcountll(i) << '\n';
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}