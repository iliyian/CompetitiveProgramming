// date: 2025-01-30 15:51:20
// tag: 又是他妈的高rating的暴力，草
// 可二分性是容易想到的，手玩一下就可以发现可以整体减1
// 可暴力性在于这种某个数减某个数加，然后变为某个要求数的，只要不是加减相同的值，似乎都是log的

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];  
  }
  bool f = true;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[0]) {
      f = false;
      break;
    }
  }
  if (f) {
    std::cout << 0 << '\n';
    return;
  }
  auto check = [&](int mid, bool out) {
    bool f = false;
    auto b = a;
    int ans = 0;
    while (!f) {
      f = true;
      for (int i = 0; i < n; i++) {
        if (b[i] > mid) {
          f = false;
          if ((b[i] - mid) % 2) {
            b[(i + n - 1) % n] -= 2;
            b[i]++;
            ans++;
          }
          int d = (b[i] - mid) / 2;
          b[(i + 1) % n] += d;
          ans += d;
          b[i] = mid;
        }
      }
    }
    // std::cerr << mid << '\n';
    // for (auto i : b) {
    //   std::cerr << i << ' ';
    // }
    // std::cerr << '\n';
    for (int i = 0; i < n; i++) {
      if (b[i] != b[(i + 1) % n]) {
        return false;
      }
    }
    if (out) {
      std::cout << ans << '\n';
    }
    return true;
  };
  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid, false)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  // std::cerr << ans << '\n';
  if (ans == -1) {
    std::cout << -1 << '\n';
    return;
  }
  check(ans, true);
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