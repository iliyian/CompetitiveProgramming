#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  bool has0 = false, has1 = false;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    has0 |= a[i] == 0;
    has1 |= a[i] != 0;
  }
  if (!has0) {
    std::cout << 1 << '\n';
    std::cout << 1 << ' ' << n << '\n';
    return;
  }
  if (!has1) {
    std::cout << 3 << '\n';
    std::cout << n - 1 << ' ' << n << '\n';
    std::cout << 1 << ' ' << n - 2 << '\n';
    std::cout << 1 << ' ' << 2 << '\n';
    return;
  }
  if (a[1] == 0 && a[n] == 0) {
    std::cout << 3 << '\n';
    std::cout << 1 << ' ' << 2 << '\n';
    std::cout << 2 << ' ' << n - 1 << '\n';
    std::cout << 1 << ' ' << 2 << '\n';
    return;
  }
  if (a[1] == 0) {
    std::cout << 2 << '\n';
    std::cout << 1 << ' ' << n - 1 << '\n';
    std::cout << 1 << ' ' << 2 << '\n';
    return;
  }
  if (a[n] == 0) {
    std::cout << 2 << '\n';
    std::cout << 2 << ' ' << n << '\n';
    std::cout << 1 << ' ' << 2 << '\n';
    return;
  }
  int l = 1, r = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      r = i;
    }
  }
  std::cout << 2 << '\n';
  std::cout << l << ' ' << r << '\n';
  std::cout << 1 << ' ' << n - (r - l) << '\n';
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