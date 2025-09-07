// date: 2025-07-28 18:32:40
// tag: 值域左区间可以大于0

#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int l = -1, r = -1;
  int mx = LLONG_MIN / 3, mn = LLONG_MAX / 3;
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      if (l == -1) l = i;
      r = i;
    }
  }
  if (l == -1) {
    std::cout << 0 << ' ' << (n + 1) * (n + 1) % mod * ((n + 1) * n / 2) % mod << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i >= l && i <= r) {
      if (a[i] > 0) {
        mx = std::max(mx, a[i]);
        mn = std::min(mn, a[i]);
      }
    }
  }
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
  }
  std::cout << a[r] - (l == 0 ? 0 : a[l - 1]) << ' ';
  std::cout << (n - mx + 1) * (mn + n + 1) % mod * (l + 1) % mod * (n - r) % mod << '\n';
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