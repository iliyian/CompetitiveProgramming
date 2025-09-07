#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), c, pos(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    pos[a[i]] = i;
    if (c.empty() || a[i] < c.back()) {
      c.push_back(a[i]);
    } else *std::ranges::lower_bound(c, a[i], std::greater<>()) = a[i];
  }
  for (auto i : c) {
    b[pos[i]] = 1;
  }
  // for (int i = 0; i < n; i++) {
  //   std::cerr << b[i] << ' ';
  // }
  // std::cerr << '\n';
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i * (n - i + 1);
  }
  for (int i = 0; i < n - 1; i++) {
    if (b[i] == 0) {
      ans -= (i + 1) * (n - i - 1);
    }
  }
  std::cout << ans << '\n';
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