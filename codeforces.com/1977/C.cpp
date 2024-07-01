// date: 2024-06-28 21:52:11
// tag: lcm溢出

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int lcm = 1;
  bool f = false;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    lcm = std::lcm(lcm, a[i]);
    if (lcm > 1e9) {
      f = true;
    }
  }
  if (f || std::find(a.begin(), a.end(), lcm) == a.end()) {
    std::cout << n << '\n';
    return;
  }
  int ans = 0;
  auto check = [&](int x) {
    if (std::find(a.begin(), a.end(), x) != a.end()) {
      return;
    }
    int cur = 0, lcm = 1;
    for (int i = 0; i < n; i++) {
      if (x % a[i] == 0) {
        lcm = std::lcm(lcm, a[i]);
        cur++;
      }
    }
    if (lcm == x) {
      ans = std::max(ans, cur);
    }
  };
  for (int i = 2; i * i <= lcm; i++) {
    if (lcm % i == 0) {
      check(lcm / i);
      check(i);
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}