// date: 2025-05-06 19:52:09
// tag: 关键在于CF不可能出实现上十分复杂的题的。因此只要实现很复杂基本可以确定是思路错了......

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n + 1);
  int p;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] == x) {
      p = i;
    }
  }
  int l = 1, r = n + 1;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (a[mid] <= x) l = mid;
    else r = mid;
  }
  if (a[l] == x) {
    std::cout << 0 << '\n';
    return;
  }
  std::cout << 1 << '\n';
  std::cout << l << ' ' << p << '\n';
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